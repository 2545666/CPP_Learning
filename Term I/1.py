import numpy as np
import matplotlib.pyplot as plt

# 传递函数 H(s) = 0.05*(s+1)/(s*(s**2/16 + s/4 + 1)), s=jω
def H(w):
    s = 1j * w
    return 0.05*(s+1)/(s*(s**2/16 + s/4 + 1))

w = np.logspace(-1, 2, 1000)  # 0.1~100 rad/s
mag = 20*np.log10(np.abs(H(w)))
phase = np.angle(H(w), deg=True)

# 渐近线幅值
mag_asym = np.zeros_like(w)
KdB = 20*np.log10(0.05)
for i,wi in enumerate(w):
    if wi < 1:
        mag_asym[i] = KdB -20*np.log10(wi)
    elif 1<=wi<4:
        mag_asym[i] = KdB
    else:
        mag_asym[i] = KdB -40*np.log10(wi/4)

# 绘图
fig, (ax1,ax2) = plt.subplots(2,1,figsize=(10,8),sharex=True)
# 幅频
ax1.semilogx(w,mag,label='精确曲线')
ax1.semilogx(w,mag_asym,'r--',label='渐近直线')
ax1.set_ylabel('Magnitude (dB)')
ax1.grid(True, which="both", ls="-")
ax1.legend()
ax1.set_title('Bode Magnitude Plot')

# 相频
ax2.semilogx(w,phase,label='精确曲线')
ax2.set_ylabel('Phase (deg)')
ax2.set_xlabel('ω (rad/s)')
ax2.grid(True, which="both", ls="-")
ax2.legend()
ax2.set_title('Bode Phase Plot')
plt.tight_layout()
plt.show()