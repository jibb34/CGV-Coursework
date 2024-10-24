import numpy as np
import pandas as pd
import matplotlib.pyplot as mpl
from scipy.optimize import curve_fit


def Poly(x, A, B, C):
    y = (x + B)**A + C
    return y


PATH = str('./')
compFrame = pd.read_csv("computationTime2.csv", delimiter=',', header=None)
print(compFrame.shape[0])
opt0 = compFrame.iloc[0].values
opt1 = compFrame.iloc[1].values
opt2 = compFrame.iloc[2].values
opt3 = compFrame.iloc[3].values
print(opt0)
print(opt1)
print(opt2)
print(opt3)
X = []
for i in range(50, 100):
    X.append(2*i)

mpl.plot(X, opt0, label="No Optimization")
mpl.plot(X, opt1, label="O1")
mpl.plot(X, opt2, label="O2")
mpl.plot(X, opt3, label="O3")
mpl.legend()
mpl.show()
