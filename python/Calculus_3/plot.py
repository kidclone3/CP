import matplotlib.pyplot as plt
import numpy as np
from numpy.lib import math

# Plot of f(x):
plt.style.use('seaborn-whitegrid')

fig = plt.figure()
ax = plt.axes()

x = np.linspace(0, 2*math.pi, 1000)
y = np.log(x**2+3)
print(y)
ax.plot(x, y)

plt.show()