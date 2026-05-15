#include "CNN.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));

    // 构建LeNet-5网络
    CNN cnn(1, 28, 28);
    cnn.buildLeNet5();

    std::cout << "=== LeNet-5 CNN 手写数字识别 ===" << std::endl;
    std::cout << "架构: Input(1×28×28) → Conv(6,5×5) → Pool(2×2) → "
              << "Conv(16,5×5) → Pool(2×2) → Conv(120,5×5) → FC(84) → FC(10)"
              << std::endl << std::endl;

    // 模拟训练过程
    std::cout << "--- 模拟训练 (演示用) ---" << std::endl;

    // 模拟10个epoch
    for (int epoch = 0; epoch < 10; ++epoch) {
        double totalLoss = 0.0;
        int correct = 0;

        // 模拟600个训练样本
        for (int sample = 0; sample < 600; ++sample) {
            // 生成随机图像和标签
            Tensor3D input(1, 28, 28);
            for (int c = 0; c < 1; ++c)
                for (int h = 0; h < 28; ++h)
                    for (int w = 0; w < 28; ++w)
                        input.at(c, h, w) = (std::rand() % 256) / 255.0;

            int label = std::rand() % 10;
            auto target = MNISTLoader::oneHot(label);

            // 前向传播
            auto output = cnn.forward(input);
            double loss = 0.0;
            for (int i = 0; i < 10; ++i)
                loss -= target[i] * std::log(std::max(output[i], 1e-10));
            totalLoss += loss;

            // 简单统计
            int pred = 0;
            double maxProb = output[0];
            for (int i = 1; i < 10; ++i) {
                if (output[i] > maxProb) {
                    maxProb = output[i];
                    pred = i;
                }
            }
            if (pred == label) correct++;
        }

        std::cout << "Epoch " << epoch + 1 << "/10 - Loss: "
                  << totalLoss / 600 << " - Accuracy: "
                  << (correct * 100.0 / 600) << "%" << std::endl;
    }

    // 测试预测
    std::cout << "\n--- 预测测试 ---" << std::endl;
    Tensor3D testImg(1, 28, 28);
    for (int h = 0; h < 28; ++h)
        for (int w = 0; w < 28; ++w)
            testImg.at(0, h, w) = (std::rand() % 256) / 255.0;

    auto result = cnn.forward(testImg);
    int predicted = 0;
    double maxProb = result[0];
    for (int i = 1; i < 10; ++i) {
        if (result[i] > maxProb) {
            maxProb = result[i];
            predicted = i;
        }
    }

    std::cout << "预测数字: " << predicted << std::endl;
    std::cout << "各数字概率: ";
    for (int i = 0; i < 10; ++i)
        std::cout << i << ":" << result[i] << " ";
    std::cout << std::endl;

    return 0;
}