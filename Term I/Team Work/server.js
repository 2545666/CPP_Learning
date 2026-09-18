const express = require('express');
const { spawn } = require('child_process');
const path = require('path');
const cors = require('cors');

const app = express();
app.use(cors());
app.use(express.json({ limit: '5mb' }));
app.use(express.static('public')); // 静态文件目录

// 启动 C++ 引擎子进程（使用绝对路径）
const enginePath = path.join(__dirname, 'main_engine.exe');
const cnnEngine = spawn(enginePath);

let currentRes = null;
let outputBuffer = '';
let engineAlive = true;

// ==================== 进程生命周期监听 ====================
cnnEngine.on('error', (err) => {
    console.error(`[CNN Engine Error] Failed to start engine: ${err.message}`);
    console.error(`[CNN Engine Error] Engine path: ${enginePath}`);
    engineAlive = false;
});

cnnEngine.on('exit', (code, signal) => {
    console.error(`[CNN Engine Exit] Process exited with code ${code}, signal ${signal}`);
    engineAlive = false;
});

cnnEngine.on('close', (code, signal) => {
    console.error(`[CNN Engine Close] Process closed with code ${code}, signal ${signal}`);
    engineAlive = false;
});

// ==================== 监听 C++ 输出 ====================
cnnEngine.stdout.on('data', (data) => {
    outputBuffer += data.toString();
    // 检查是否输出了完整的 JSON（以换行符分隔）
    try {
        if (outputBuffer.includes('\n')) {
            const jsonStr = outputBuffer.split('\n')[0].trim();
            if (jsonStr.length > 0) {
                const result = JSON.parse(jsonStr);
                if (currentRes) {
                    currentRes.json(result);
                    currentRes = null;
                }
                outputBuffer = outputBuffer.substring(jsonStr.length + 1);
            }
        }
    } catch (e) {
        console.error(`[JSON Parse Error] ${e.message}`);
        console.error(`[JSON Parse Error] Buffer content: ${outputBuffer.substring(0, 200)}`);
        // 数据包未接收完整，等待下一次 data 事件
    }
});

cnnEngine.stderr.on('data', (data) => {
    console.error(`[CNN Engine Stderr]: ${data}`);
});

// ==================== 处理前端的预测请求 ====================
app.post('/api/predict', (req, res) => {
    // 检查引擎是否存活
    if (!engineAlive || cnnEngine.killed) {
        console.error('[API Error] CNN Engine is not alive');
        return res.status(500).json({ 
            error: "CNN Engine is not running. Please restart the server." 
        });
    }

    // 检查是否有请求正在处理
    if (currentRes) {
        return res.status(429).json({ error: "Engine is busy, please try again later" });
    }

    // 验证输入数据
    const pixels = req.body.pixels;
    if (!pixels || !Array.isArray(pixels) || pixels.length !== 784) {
        return res.status(400).json({ error: "Invalid pixel data: expected array of 784 numbers" });
    }

    // 验证像素值范围
    if (!pixels.every(p => typeof p === 'number' && p >= 0 && p <= 1)) {
        return res.status(400).json({ error: "Pixel values must be numbers between 0 and 1" });
    }

    currentRes = res;
    try {
        // 将数组转化为以空格分隔的字符串输入给 C++
        const inputStr = pixels.join(' ') + '\n';
        cnnEngine.stdin.write(inputStr);
    } catch (err) {
        console.error(`[Write Error] Failed to write to engine stdin: ${err.message}`);
        currentRes = null;
        return res.status(500).json({ error: "Failed to communicate with CNN Engine" });
    }
});

// ==================== 健康检查端点 ====================
app.get('/api/health', (req, res) => {
    if (engineAlive && !cnnEngine.killed) {
        res.json({ status: 'ok', engine: 'running' });
    } else {
        res.status(503).json({ status: 'error', engine: 'not running' });
    }
});

const PORT = 3000;
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
    console.log(`CNN Engine path: ${enginePath}`);
});
