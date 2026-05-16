//CNN.h - 卷积神经网络头文件
#ifndef CNN_H
#define CNN_H

#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

// 激活函数类型
enum class ActivationType { ReLU, Sigmoid, Softmax };

// 3D矩阵结构 (通道 × 高度 × 宽度)
struct Tensor3D {
    int channels, height, width;
    std::vector<std::vector<std::vector<double>>> data;

    Tensor3D() : channels(0), height(0), width(0) {}
    Tensor3D(int c, int h, int w) : channels(c), height(h), width(w) {
        data.resize(c, std::vector<std::vector<double>>(h, std::vector<double>(w, 0.0)));
    }

    void fill(double value) {
        for (auto& ch : data)
            for (auto& row : ch)
                for (auto& val : row)
                    val = value;
    }

    void randomFill(double scale = 0.1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, scale);
        for (auto& ch : data)
            for (auto& row : ch)
                for (auto& val : row)
                    val = d(gen);
    }

    double& at(int c, int h, int w) { return data[c][h][w]; }
    const double& at(int c, int h, int w) const { return data[c][h][w]; }
};

// 2D矩阵结构
struct Matrix {
    int rows, cols;
    std::vector<std::vector<double>> data;

    Matrix() : rows(0), cols(0) {}
    Matrix(int r, int c) : rows(r), cols(c) {
        data.resize(r, std::vector<double>(c, 0.0));
    }

    void fill(double value) {
        for (auto& row : data)
            for (auto& val : row)
                val = value;
    }

    void randomFill(double scale = 0.1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> d(0, scale);
        for (auto& row : data)
            for (auto& val : row)
                val = d(gen);
    }

    double dot(const std::vector<double>& vec) const {
        double sum = 0;
        for (int i = 0; i < rows; ++i) {
            sum += data[i][0] * vec[i];
        }
        return sum;
    }

    std::vector<double> operator*(const std::vector<double>& vec) const {
        std::vector<double> result(rows, 0.0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i] += data[i][j] * vec[j];
            }
        }
        return result;
    }
// 新增：矩阵转置乘以向量 (用于反向传播传递梯度)
    std::vector<double> transposeMultiply(const std::vector<double>& vec) const {
        std::vector<double> result(cols, 0.0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[j] += data[i][j] * vec[i];
            }
        }
        return result;
    }
}; // Matrix 结束 

// ==================== 激活函数 ====================
class Activation {
public:
    static Tensor3D relu(const Tensor3D& input) {
        Tensor3D output(input.channels, input.height, input.width);
        for (int c = 0; c < input.channels; ++c)
            for (int h = 0; h < input.height; ++h)
                for (int w = 0; w < input.width; ++w) {
                    output.at(c, h, w) = std::max(0.0, input.at(c, h, w));
                }
        return output;
    }
    // 新增：针对一维向量的全连接层 ReLU 激活函数
    static std::vector<double> relu(const std::vector<double>& input) {
        std::vector<double> output(input.size());
        for (size_t i = 0; i < input.size(); ++i) {
            output[i] = std::max(0.0, input[i]);
        }
        return output;
    }
    static Tensor3D reluGradient(const Tensor3D& input, const Tensor3D& gradient) {
        Tensor3D output(input.channels, input.height, input.width);
        for (int c = 0; c < input.channels; ++c)
            for (int h = 0; h < input.height; ++h)
                for (int w = 0; w < input.width; ++w) {
                    output.at(c, h, w) = (input.at(c, h, w) > 0) ? gradient.at(c, h, w) : 0;
                }
        return output;
    }

    static std::vector<double> softmax(const std::vector<double>& input) {
        std::vector<double> output(input.size());
        double maxVal = *std::max_element(input.begin(), input.end());
        double sum = 0.0;
        for (size_t i = 0; i < input.size(); ++i) {
            output[i] = std::exp(input[i] - maxVal);
            sum += output[i];
        }
        for (size_t i = 0; i < output.size(); ++i)
            output[i] /= sum;
        return output;
    }
};

// ==================== 卷积层 ====================
class ConvLayer {
public:
    int inChannels, outChannels, kernelSize, stride, padding;
    std::vector<Tensor3D> kernels;      // [outChannel][inChannel][kH][kW]
    std::vector<double> biases;
    Tensor3D inputCache;

    ConvLayer(int inC, int outC, int kSize, int stride = 1, int padding = 0)
        : inChannels(inC), outChannels(outC), kernelSize(kSize),
          stride(stride), padding(padding) {
        kernels.resize(outC);
        for (int oc = 0; oc < outC; ++oc) {
            kernels[oc].channels = inC;
            kernels[oc].height = kSize;
            kernels[oc].width = kSize;
            kernels[oc].data.resize(inC,
                std::vector<std::vector<double>>(kSize, std::vector<double>(kSize)));
            kernels[oc].randomFill(0.05);
        }
        biases.resize(outC, 0.0);
    }

    Tensor3D forward(const Tensor3D& input) {
        inputCache = input;
        int outH = (input.height + 2 * padding - kernelSize) / stride + 1;
        int outW = (input.width + 2 * padding - kernelSize) / stride + 1;
        Tensor3D output(outChannels, outH, outW);

        for (int oc = 0; oc < outChannels; ++oc) {
            for (int oh = 0; oh < outH; ++oh) {
                for (int ow = 0; ow < outW; ++ow) {
                    double sum = 0.0;
                    for (int ic = 0; ic < inChannels; ++ic) {
                        for (int kh = 0; kh < kernelSize; ++kh) {
                            for (int kw = 0; kw < kernelSize; ++kw) {
                                int ih = oh * stride - padding + kh;
                                int iw = ow * stride - padding + kw;
                                if (ih >= 0 && ih < input.height && iw >= 0 && iw < input.width) {
                                    sum += kernels[oc].at(ic, kh, kw) * input.at(ic, ih, iw);
                                }
                            }
                        }
                    }
                    output.at(oc, oh, ow) = sum + biases[oc];
                }
            }
        }
        return output;
    }
};

// ==================== 池化层 ====================
class PoolingLayer {
public:
    int poolSize, stride;
    Tensor3D inputCache;
    std::vector<std::vector<std::pair<int, int>>> maxPositions;

    PoolingLayer(int pSize = 2, int stride = 2)
        : poolSize(pSize), stride(stride) {}

    Tensor3D forward(const Tensor3D& input) {
        inputCache = input;
        int outH = (input.height - poolSize) / stride + 1;
        int outW = (input.width - poolSize) / stride + 1;
        Tensor3D output(input.channels, outH, outW);
        maxPositions.resize(input.channels);

        for (int c = 0; c < input.channels; ++c) {
            maxPositions[c].resize(outH * outW);
            for (int oh = 0; oh < outH; ++oh) {
                for (int ow = 0; ow < outW; ++ow) {
                    double maxVal = -1e9;
                    std::pair<int, int> maxPos(0, 0);
                    for (int ph = 0; ph < poolSize; ++ph) {
                        for (int pw = 0; pw < poolSize; ++pw) {
                            double val = input.at(c, oh * stride + ph, ow * stride + pw);
                            if (val > maxVal) {
                                maxVal = val;
                                maxPos = {ph, pw};
                            }
                        }
                    }
                    output.at(c, oh, ow) = maxVal;
                    maxPositions[c][oh * outW + ow] = maxPos;
                }
            }
        }
        return output;
    }
};

// ==================== 全连接层 ====================
class FullyConnectedLayer {
public:
    int inputSize, outputSize;
    Matrix weights;
    std::vector<double> bias;
    std::vector<double> inputCache;

    FullyConnectedLayer(int inSize, int outSize) : inputSize(inSize), outputSize(outSize) {
        weights = Matrix(outSize, inSize);
        weights.randomFill(0.05);
        bias.resize(outSize, 0.0);
    }

    std::vector<double> forward(const std::vector<double>& input) {
        inputCache = input;
        std::vector<double> output = weights * input;
        for (int i = 0; i < outputSize; ++i)
            output[i] += bias[i];
        return output;
    }
};

// ==================== 批量归一化层 ====================
class BatchNormLayer {
public:
    int channels, height, width;
    std::vector<double> gamma, beta;
    std::vector<double> runningMean, runningVar;
    double epsilon = 1e-5, momentum = 0.1;
    Tensor3D inputCache;

    BatchNormLayer(int c, int h, int w) : channels(c), height(h), width(w) {
        gamma.resize(c, 1.0);
        beta.resize(c, 0.0);
        runningMean.resize(c, 0.0);
        runningVar.resize(c, 1.0);
    }

    Tensor3D forward(const Tensor3D& input) {
        inputCache = input;
        Tensor3D output(channels, height, width);

        for (int c = 0; c < channels; ++c) {
            double mean = 0.0;
            for (int h = 0; h < height; ++h)
                for (int w = 0; w < width; ++w)
                    mean += input.at(c, h, w);
            mean /= (height * width);

            double var = 0.0;
            for (int h = 0; h < height; ++h)
                for (int w = 0; w < width; ++w) {
                    double diff = input.at(c, h, w) - mean;
                    var += diff * diff;
                }
            var /= (height * width);

            for (int h = 0; h < height; ++h)
                for (int w = 0; w < width; ++w) {
                    double norm = (input.at(c, h, w) - mean) / std::sqrt(var + epsilon);
                    output.at(c, h, w) = gamma[c] * norm + beta[c];
                }
        }
        return output;
    }
};

// ==================== Dropout层 ====================
class DropoutLayer {
public:
    double dropRate;
    std::vector<double> mask;
    bool training;

    DropoutLayer(double rate) : dropRate(rate), training(true) {}

    std::vector<double> forward(const std::vector<double>& input) {
        if (!training) return input;
        std::vector<double> output(input.size());
        mask.resize(input.size());
        std::random_device rd;
        std::mt19937 gen(rd());
        std::bernoulli_distribution d(1.0 - dropRate);

        for (size_t i = 0; i < input.size(); ++i) {
            if (d(gen)) {
                output[i] = input[i];
                mask[i] = 1.0 / (1.0 - dropRate);
            } else {
                output[i] = 0.0;
                mask[i] = 0.0;
            }
        }
        return output;
    }
};

// ==================== CNN网络 ====================
class CNN {
public:
    std::vector<ConvLayer*> convLayers;
    std::vector<PoolingLayer*> poolLayers;
    std::vector<FullyConnectedLayer*> fcLayers;
    std::vector<double> learningRate;
    int inputChannels, inputHeight, inputWidth;

    CNN(int inC, int inH, int inW) : inputChannels(inC), inputHeight(inH), inputWidth(inW) {}

    ~CNN() {
        for (auto p : convLayers) delete p;
        for (auto p : poolLayers) delete p;
        for (auto p : fcLayers) delete p;
    }

    // LeNet-5架构
 void buildLeNet5() {
        // C1: 卷积层 (1×28×28 → 6×28×28)，引入 padding=2 补齐 32x32 等效尺寸
        convLayers.push_back(new ConvLayer(1, 6, 5, 1, 2));
        // S2: 池化层 (6×28×28 → 6×14×14)
        poolLayers.push_back(new PoolingLayer(2, 2));
        // C3: 卷积层 (6×14×14 → 16×10×10)
        convLayers.push_back(new ConvLayer(6, 16, 5, 1, 0));
        // S4: 池化层 (16×10×10 → 16×5×5)
        poolLayers.push_back(new PoolingLayer(2, 2));
        // C5: 卷积层 (16×5×5 → 120×1×1)
        convLayers.push_back(new ConvLayer(16, 120, 5, 1, 0));
        // FC1: 全连接层 (120 → 84)
        fcLayers.push_back(new FullyConnectedLayer(120, 84));
        // FC2: 全连接层 (84 → 10)
        fcLayers.push_back(new FullyConnectedLayer(84, 10));
    }

    // 前向传播
    std::vector<double> forward(const Tensor3D& input) {
        Tensor3D x = input;

        // 卷积 + ReLU + 池化 (C1 → S2)
        x = convLayers[0]->forward(x);
        x = Activation::relu(x);
        x = poolLayers[0]->forward(x);

        // 卷积 + ReLU + 池化 (C3 → S4)
        x = convLayers[1]->forward(x);
        x = Activation::relu(x);
        x = poolLayers[1]->forward(x);

        // 卷积 + ReLU (C5)
        x = convLayers[2]->forward(x);
        x = Activation::relu(x);

        // 展平
        std::vector<double> flat;
        for (int c = 0; c < x.channels; ++c)
            for (int h = 0; h < x.height; ++h)
                for (int w = 0; w < x.width; ++w)
                    flat.push_back(x.at(c, h, w));

        // 全连接层
        flat = fcLayers[0]->forward(flat);
        flat = Activation::relu(flat);
        flat = fcLayers[1]->forward(flat);

        // Softmax输出
        return Activation::softmax(flat);
    }

    // 训练一个样本
    double train(const Tensor3D& input, const std::vector<double>& target) {
        // 前向传播
        auto output = forward(input);

        // 计算交叉熵损失
        double loss = 0.0;
        for (size_t i = 0; i < target.size(); ++i) {
            loss -= target[i] * std::log(std::max(output[i], 1e-10));
        }

        // 反向传播 (仅限全连接层)
        std::vector<double> gradFC2 = output;
        for (size_t i = 0; i < target.size(); ++i) {
            gradFC2[i] -= target[i]; // Softmax + CrossEntropy 组合梯度
        }

        // 1. 在更新 FC2 权重之前，先计算回传给 FC1 的梯度 (使用转置乘法)
        std::vector<double> gradFC1_out = fcLayers[1]->weights.transposeMultiply(gradFC2);

        // 2. 更新 FC2 权重
        updateFCGradient(fcLayers[1], gradFC2);

        // 3. 应用 FC1 后激活函数 ReLU 的导数
        // 需获取 FC1 未经 ReLU 的原始输出进行符号判断
        std::vector<double> fc1_unactivated = fcLayers[0]->forward(fcLayers[0]->inputCache);
        std::vector<double> gradFC1_in(gradFC1_out.size(), 0.0);
        for (size_t i = 0; i < gradFC1_out.size(); ++i) {
            gradFC1_in[i] = (fc1_unactivated[i] > 0) ? gradFC1_out[i] : 0.0;
        }

        // 4. 更新 FC1 权重
        updateFCGradient(fcLayers[0], gradFC1_in);
        
        // 注：若要网络具备完整学习能力，还需补充展平层到 C5 的梯度重构以及所有 ConvLayer 的反向传播代码。

        return loss;
    }
    // ---------------- 在 CNN 类中新增持久化方法 ----------------
    void saveModel(const std::string& filepath) {
        std::ofstream outFile(filepath, std::ios::binary);
        if (!outFile.is_open()) {
            std::cerr << "无法创建模型保存文件: " << filepath << std::endl;
            return;
        }

        // 1. 保存卷积层权重与偏置 (必须保存，否则随机初始化的特征提取器会变)
        for (auto conv : convLayers) {
            for (int oc = 0; oc < conv->outChannels; ++oc) {
                for (int ic = 0; ic < conv->inChannels; ++ic) {
                    for (int kh = 0; kh < conv->kernelSize; ++kh) {
                        outFile.write(reinterpret_cast<const char*>(conv->kernels[oc].data[ic][kh].data()), 
                                      conv->kernelSize * sizeof(double));
                    }
                }
            }
            outFile.write(reinterpret_cast<const char*>(conv->biases.data()), conv->outChannels * sizeof(double));
        }

        // 2. 保存全连接层权重与偏置
        for (auto fc : fcLayers) {
            for (int i = 0; i < fc->outputSize; ++i) {
                outFile.write(reinterpret_cast<const char*>(fc->weights.data[i].data()), 
                              fc->inputSize * sizeof(double));
            }
            outFile.write(reinterpret_cast<const char*>(fc->bias.data()), fc->outputSize * sizeof(double));
        }

        outFile.close();
        std::cout << "模型参数成功保存至: " << filepath << std::endl;
    }

    void loadModel(const std::string& filepath) {
        std::ifstream inFile(filepath, std::ios::binary);
        if (!inFile.is_open()) {
            std::cerr << "未找到模型文件，将使用随机初始化的权重。" << std::endl;
            return;
        }

        // 1. 读取卷积层权重与偏置
        for (auto conv : convLayers) {
            for (int oc = 0; oc < conv->outChannels; ++oc) {
                for (int ic = 0; ic < conv->inChannels; ++ic) {
                    for (int kh = 0; kh < conv->kernelSize; ++kh) {
                        inFile.read(reinterpret_cast<char*>(conv->kernels[oc].data[ic][kh].data()), 
                                    conv->kernelSize * sizeof(double));
                    }
                }
            }
            inFile.read(reinterpret_cast<char*>(conv->biases.data()), conv->outChannels * sizeof(double));
        }

        // 2. 读取全连接层权重与偏置
        for (auto fc : fcLayers) {
            for (int i = 0; i < fc->outputSize; ++i) {
                inFile.read(reinterpret_cast<char*>(fc->weights.data[i].data()), 
                            fc->inputSize * sizeof(double));
            }
            inFile.read(reinterpret_cast<char*>(fc->bias.data()), fc->outputSize * sizeof(double));
        }

        inFile.close();
        std::cout << "模型参数成功加载自: " << filepath << std::endl;
    }

private:
    void updateFCGradient(FullyConnectedLayer* layer, const std::vector<double>& grad) {
        for (int i = 0; i < layer->outputSize; ++i) {
            for (int j = 0; j < layer->inputSize; ++j) {
                layer->weights.data[i][j] -= 0.01 * grad[i] * layer->inputCache[j];
            }
            layer->bias[i] -= 0.01 * grad[i];
        }
    }
};

// ==================== MNIST数据加载 ====================
class MNISTLoader {
public:
    static Tensor3D loadImage(const std::string& filename) {
        std::ifstream file(filename, std::ios::binary);
        Tensor3D img(1, 28, 28);
        if (file.is_open()) {
            for (int h = 0; h < 28; ++h)
                for (int w = 0; w < 28; ++w) {
                    unsigned char pixel;
                    file.read(reinterpret_cast<char*>(&pixel), 1);
                    img.at(0, h, w) = pixel / 255.0;
                }
        }
        return img;
    }

    static std::vector<double> oneHot(int label, int classes = 10) {
        std::vector<double> vec(classes, 0.0);
        vec[label] = 1.0;
        return vec;
    }
};

#endif // CNN_H