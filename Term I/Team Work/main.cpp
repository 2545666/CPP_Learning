#include "CNN.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// 传入一张预处理好的图像，返回预测的数字标签
int predictDigit(CNN& cnn, const Tensor3D& inputImage) {
    // 执行前向传播
    std::vector<double> probabilities = cnn.forward(inputImage);

    // 解析最大概率对应的数字 (Argmax)
    int predictedClass = 0;
    double maxConfidence = probabilities[0];
    for (size_t i = 1; i < probabilities.size(); ++i) {
        if (probabilities[i] > maxConfidence) {
            maxConfidence = probabilities[i];
            predictedClass = i;
        }
    }
    return predictedClass;
}

int main() {
    std::srand(std::time(nullptr));

    // 构建LeNet-5网络
    CNN cnn(1, 28, 28);
    cnn.buildLeNet5();

    std::cout << "=== LeNet-5 CNN 手写数字识别 ===" << std::endl;
    std::cout << "架构: Input(1x28x28) -> Conv(6,5x5) -> Pool(2x2) -> "
              << "Conv(16,5x5) -> Pool(2x2) -> Conv(120,5x5) -> FC(84) -> FC(10)"
              << std::endl << std::endl;

    // 控制当前运行是训练模式还是推理模式
    // 在实际工程中，可通过命令行参数 (如 argc, argv) 动态控制
    bool isTrainingMode = true; 
    std::string modelFile = "lenet5_weights.bin";

    if (isTrainingMode) {
        std::cout << "--- 启动训练流程 ---" << std::endl;

        // 模拟10个epoch
        for (int epoch = 0; epoch < 10; ++epoch) {
            double totalLoss = 0.0;
            int correct = 0;

            // 模拟600个训练样本 (单样本过拟合测试)
            for (int sample = 0; sample < 600; ++sample) {
                Tensor3D input(1, 28, 28);
                for (int c = 0; c < 1; ++c)
                    for (int h = 0; h < 28; ++h)
                        for (int w = 0; w < 28; ++w)
                            input.at(c, h, w) = (h > 10 && h < 18 && w > 10 && w < 18) ? 1.0 : 0.0;

                int label = 3; // 固定标签
                auto target = MNISTLoader::oneHot(label);

                // 前向传播与训练
                double loss = cnn.train(input, target); 
                totalLoss += loss;

                // 统计准确率
                if (predictDigit(cnn, input) == label) correct++;
            }

            std::cout << "Epoch " << epoch + 1 << "/10 - Loss: "
                      << totalLoss / 600 << " - Accuracy: "
                      << (correct * 100.0 / 600) << "%" << std::endl;
        }

        // 训练完成后，立即保存模型参数到本地硬盘
        cnn.saveModel(modelFile);

    } else {
        std::cout << "--- 启动纯推理流程 ---" << std::endl;
        // 如果不是训练模式，直接从硬盘读取之前训练好的权重
        cnn.loadModel(modelFile);
    }

    // ==========================================
    // 独立的预测测试环节 (验证加载后的模型是否有效)
    // ==========================================
    std::cout << "\n--- 预测测试 ---" << std::endl;
    
    // 生成一张和训练时相同特征的测试图像
    Tensor3D testImg(1, 28, 28);
    for (int h = 0; h < 28; ++h)
        for (int w = 0; w < 28; ++w)
            testImg.at(0, h, w) = (h > 10 && h < 18 && w > 10 && w < 18) ? 1.0 : 0.0;

    int predicted = predictDigit(cnn, testImg);
    std::vector<double> result = cnn.forward(testImg);

    std::cout << "预测数字: " << predicted << std::endl;
    std::cout << "各数字概率: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << i << ":" << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}