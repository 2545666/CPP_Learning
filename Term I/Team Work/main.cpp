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
    // === [阶段 1: 资源预热与模型加载] ===
    CNN cnn(1, 28, 28);
    cnn.buildLeNet5();
    
    // 尝试加载模型预训练权重
    cnn.loadModel("lenet5_weights.bin");

    // === [阶段 2: 建立流监听与守护进程化] ===
    // 进入无限循环，等待上游进程（如 Node.js）通过标准输入传入数据
    std::string inputStr;
    while (std::cin >> inputStr) {
        if (inputStr == "exit") break;

        // === [阶段 3: 张量重组与数据清洗] ===
        Tensor3D inputImg(1, 28, 28);
        
        // 读取并映射 784 个像素值
        try {
            inputImg.at(0, 0, 0) = std::stod(inputStr);
            for (int i = 1; i < 784; ++i) {
                std::cin >> inputStr;
                int h = i / 28;
                int w = i % 28;
                inputImg.at(0, h, w) = std::stod(inputStr);
            }
        } catch (...) {
            // 异常隔离：拦截非法字符或流截断
            std::cout << "{\"error\": \"Invalid input\"}" << std::endl;
            continue;
        }

        // === [阶段 4: 前向推理与 API 序列化] ===
        // 触发计算引擎进行前向传播
        std::vector<double> probs = cnn.forward(inputImg);

        // 提取预测概率及缓存特征，构造标准 JSON 响应直接输出至 stdout
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