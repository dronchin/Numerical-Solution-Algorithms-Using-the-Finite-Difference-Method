import numpy as np
import matplotlib.pyplot as plt


filelist1 = ['LUout1.txt','LUout2.txt','LUout3.txt','LUout4.txt']
errorlist1 = []
for filename in filelist1:
    with open(filename, 'r') as data:

        largest = 0

        for line in data:
            numbers_float = list(map(float, line.split()))
            currenterror = numbers_float[3]
            if currenterror < largest:
                largest = currenterror
        errorlist1.append(largest)
errorlist2 = [-1.1005822, -3.0793984, -5.0791834, -7.0791825, -9.0807202, -9.9439925, -10.175691, -9.7048604,-9.6534015,-8.9023721,-8.5269139]
half = 3.16227766
n1 = range(1,len(filelist1)+1)
plt.plot(n1, errorlist1, label="LU")
n2 = np.log10(np.array([10,100,1000,10000,100000,half*100000,1000000, half*1000000, 10000000, half*10000000, 100000000]))
plt.plot(n2, errorlist2, label="Simple")
#plt.xlim((0,8))
#plt.ylim(-14,0)
plt.xlabel("log(n)")
plt.ylabel("RelativeError")
plt.title("RelativeError vs matrix of size nxn")
plt.legend(loc="best")
plt.savefig("Algorithm error.png", format="png")
plt.show()
