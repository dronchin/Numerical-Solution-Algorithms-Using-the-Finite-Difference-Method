import numpy as np
import matplotlib.pyplot as plt

LuTimes = np.array([0.000261, 0.001485, 0.4332917,3.34279,11.3546,28.0309])
GenTimes = np.array([9.236e-7,4.08e-6,3.53e-5,0.000407,0.00434,0.0436,0.433,4.369])
SimpTimes = np.array([8.676e-7,3.8e-6,3.3e-5,2.92e-4,0.002987,0.02986,0.29703,2.984])

nlog1 = np.array([1,2,3, np.log10(2000),np.log10(3000), np.log10(4000)])
nlog2 = np.array([1,2,3,4,5,6,7,8])

plt.plot(nlog1, np.log10(LuTimes), label="LU")
plt.plot(nlog2, np.log10(GenTimes), label="General")
plt.plot(nlog2, np.log10(SimpTimes), label="Simple")
plt.xlim((0,8))
plt.xlabel("Log10(n)")
plt.ylabel("Log10(runtime)")
plt.title("Runtime vs matrix of size nxn")
plt.legend(loc="best")

plt.savefig("Algorithm timing.png", format="png")
plt.show()
