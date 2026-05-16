[输入数据: 1×28×28] 
       │
       ▼
 1. 特征提取层 (ConvLayer + PoolingLayer)
    - ConvLayers[0] (C1): 提取低级边缘特征（使用 Padding=2 保持维度）
    - PoolLayers[0] (S2): 空间下采样，减少计算量并保持平移不变性
    - ConvLayers[1] (C3) & PoolLayers[1] (S4): 提取高阶组合特征
    - ConvLayers[2] (C5): 将空间特征整合为 120 维的特征向量
       │
       ▼
 2. 数据展平 (Flatten)
    - 将 3D 张量 (120×1×1) 转化为 1D 向量 (120)
       │
       ▼
 3. 分类决策层 (FullyConnectedLayer + Activation)
    - fcLayers[0] (FC1): 120 维映射到 84 维（引入非线性 ReLU）
    - fcLayers[1] (FC2): 84 维映射到 10 维（对应数字 0-9 的得分）
       │
       ▼
 4. 概率归一化 (Softmax)
    - 将 10 维得分转化为总和为 1.0 的概率分布（输出层）