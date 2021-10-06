# import math
import random
import numpy as np
from numpy.lib import math
import scipy.integrate as integrate
import matplotlib.pyplot as plt

f = lambda x : math.log(x*x+3)

A,_ = integrate.quad(f, 0, 2*math.pi)
print(A)

def riemannL(n, a, b):
    h = (b-a)/n
    sum = 0
    for i in range(0, n):
        sum += f(a+i*h)*h
    return sum

def riemannR(n, a, b):
    h = (b-a)/n
    sum = 0
    for i in range(0, n):
        sum += f(a+(i+1)*h)*h
    return sum

def riemann(n, a, b):
    h = (b-a)/n
    sum = 0
    for i in range(0, n):
        cxi = a + i*h + random.random()*h
        sum += f(cxi)*h
    return sum

n = 50
RL = riemannL(n, 0, 2*math.pi)
RR = riemannR(n, 0, 2*math.pi)
R = riemann(n, 0, 2*math.pi)

print("RL = ", RL, ", RR = ", RR, ", R = ", R, sep = "")


# plt.style.use('seaborn-whitegrid')

# fig = plt.figure()
# ax = plt.axes()

# x = np.linspace(0, 2*math.pi, 1000)
# y = np.log(x**2+3)
# print(y)
# ax.plot(x, y)

# plt.show()

def minhhoa(a, b):
    n = [int(i) for i in range(5, 200, 10)]
    R = [0]*len(n)
    for i in range(len(n)):
        R[i] = riemann(n[i], a, b)
    A,_ = integrate.quad(f, 0, 2*math.pi)

    plt.style.use('seaborn-whitegrid')
    plt.plot(n, R, 'bo')
    plt.hlines(y = A, colors='r', linestyles='--', xmin = 0, xmax = 200 , linewidth = 2.0)
    
    plt.show()

# minhhoa(0, 2*math.pi)
# plt.style.available()
print(type(math.log))
print(type(np.log))