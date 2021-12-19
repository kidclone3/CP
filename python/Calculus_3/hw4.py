import matplotlib.pyplot as plt
import numpy as np

n = 10
x = np.linspace(0, 2, n)
y = np.linspace(0, 2, n)
xx, yy = np.meshgrid(x,y)

# C = lambda x, y : x**2 + y**2 <= 4 
P = lambda x,y: x*y
Q = lambda x,y: x**2 * y**2

plt.quiver(xx, P, Q)
plt.show()

from sympy import Curve, line_integrate, sin, cos, pi
from sympy.abc import x,y,t

C = Curve([2*cos(t), 2*sin(t)], (t, 0, pi/2))
C
line_integrate(, C, [x,y])