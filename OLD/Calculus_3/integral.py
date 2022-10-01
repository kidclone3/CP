import math
from python.Calculus_3.hw1 import f
import numpy as np
import scipy.integrate as integrate
import matplotlib.pyplot as plt

def integral_x(a, b, n): # a: src; b: dest; n = subintervals
    # f(x) = e^x
    riemann_left = 0.0
    riemann_right = 0.0
    h = (b-a)/n
    i = a
    
    for i in range(0, n):
        riemann_left += h*exp_x(a + i*h)
        riemann_right += h*exp_x(a+(i+1)*h)

    print("RL = ", riemann_left)
    print("RR = ", riemann_right)

def exp_x(x):
    return math.e**x

integral_x(0, 1, 10)

print("Quad = ", integrate.quad(exp_x, 0, 1))
math.log(x*x+3)
# print(math.pi)

