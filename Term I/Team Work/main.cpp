#include "CNN.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// 辅助函数：将 Tensor3D 转换为 JSON 数组字符串，并映射到 0-255 灰度以便前端渲染
std::string tensorToJson(const Tensor3D& t) {
    std::string json = "[";
    for (int c = 0; c < t.channels; ++c) {
        json += "[";
        for (int h = 0; h < t.height; ++h) {
            json += "[";
            for (int w = 0; w < t.width; ++w) {
                int val = std::max(0, std::min(255, static_cast<int>(t.at(c, h, w) * 255.0)));
                json += std::to_string(val);
                if (w < t.width - 1) json += ",";
            }
            json += "]";
            if (h < t.height - 1) json += ",";
        }
        json += "]";
        if (c < t.channels - 1) json += ",";
    }
    json += "]";
    return json;
}

int main() {
    CNN cnn(1, 28, 28);
    cnn.buildLeNet5();
    
    // 尝试加载模型
    cnn.loadModel("lenet5_weights.bin");

    // 进入无限循环，等待 Node.js 通过标准输入传入数据
    std::string inputStr;
    while (std::cin >> inputStr) {
        if (inputStr == "exit") break;

        Tensor3D inputImg(1, 28, 28);
        
        // 读取 784 个像素值
        try {
            inputImg.at(0, 0, 0) = std::stod(inputStr);
            for (int i = 1; i < 784; ++i) {
                std::cin >> inputStr;
                int h = i / 28;
                int w = i % 28;
                inputImg.at(0, h, w) = std::stod(inputStr);
            }
        } catch (...) {
            std::cout << "{\"error\": \"Invalid input\"}" << std::endl;
            continue;
        }

        // 前向传播
        std::vector<double> probs = cnn.forward(inputImg);

        // 构造 JSON 响应
        std::cout << "{"
                  << "\"probabilities\": [";
        for (size_t i = 0; i < probs.size(); ++i) {
            std::cout << std::fixed << std::setprecision(6) << probs[i] << (i == probs.size() - 1 ? "" : ",");
        }
        std::cout << "],"
                  << "\"c1_features\": " << tensorToJson(cnn.cache_C1) << ","
                  << "\"s4_features\": " << tensorToJson(cnn.cache_S4) 
                  << "}" << std::endl;
    }
    return 0;
}