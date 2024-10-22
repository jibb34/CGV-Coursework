import numpy as np
import pandas as pd
import matplotlib.pyplot as mpl
from scipy.optimize import curve_fit


def Poly(x, A, B, C):
    y = (x + B)**A + C
    return y


PATH = str('./')
my_data = np.genfromtxt('computationTime.csv', delimiter=',')
index_values = range(101, 202)
compTimeFrame = pd.Series(my_data, index=index_values)
parameters, covariance = curve_fit(Poly, index_values, compTimeFrame.values)
# print(compTimeFrame.values)
fit_y = Poly(index_values, parameters[0], parameters[1], parameters[2])
mpl.plot(index_values, fit_y, '-', label='fit')
mpl.plot(compTimeFrame, label='data')
mpl.legend()
print("Y = (x + " + str(parameters[1]) + ")+ ^" +
      str(parameters[0]) + "  + " + str(parameters[2]))
mpl.show()
