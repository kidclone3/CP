import numpy as np
import matplotlib.pyplot as plt

x, y = np.meshgrid(np.linspace(-2, 2, 20), np.linspace(-2, 2, 20))

u = np.log(1+y**2)
v = np.log(1+x**2)
plt.quiver(x, y, u, v)
plt.show()
