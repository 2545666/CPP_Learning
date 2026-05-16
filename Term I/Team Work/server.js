const express = require('express');
const { spawn } = require('child_process');
const path = require('path');
const cors = require('cors');

const app = express();
app.use(cors());
app.use(express.json({ limit: '5mb' }));
app.use(express.static('public')); // 静态文件目录

// 启动 C++ 引擎子进程
const cnnEngine = spawn('./main_engine.exe');

let currentRes = null;
let outputBuffer = '';

// 监听 C++ 输出
cnnEngine.stdout.on('data', (data) => {
    outputBuffer += data.toString();
    // 检查是否输出了完整的 JSON
    try {
        if (outputBuffer.includes('\n')) {
            const jsonStr = outputBuffer.split('\n')[0];
            const result = JSON.parse(jsonStr);
            if (currentRes) {
                currentRes.json(result);
                currentRes = null;
            }
            outputBuffer = outputBuffer.substring(jsonStr.length + 1);
        }
    } catch (e) {
        // 数据包未接收完整，等待下一次 data 事件
    }
});

cnnEngine.stderr.on('data', (data) => {
    console.error(`[CNN Engine Error]: ${data}`);
});

// 处理前端的预测请求
app.post('/api/predict', (req, res) => {
    if (currentRes) {
        return res.status(429).json({ error: "Engine is busy" });
    }
    const pixels = req.body.pixels; // 长度为 784 的数组
    if (!pixels || pixels.length !== 784) {
        return res.status(400).json({ error: "Invalid pixel data" });
    }

    currentRes = res;
    // 将数组转化为以空格分隔的字符串输入给 C++
    const inputStr = pixels.join(' ') + '\n';
    cnnEngine.stdin.write(inputStr);
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});