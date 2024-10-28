import numpy as np
import pandas as pd
import matplotlib.pyplot as mpl


correctArray = np.genfromtxt("./correct.csv", delimiter=',')
testArray = np.genfromtxt("./jacobiResult.csv", delimiter=',')
print((correctArray == testArray).all())
