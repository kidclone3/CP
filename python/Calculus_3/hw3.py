import numpy as np
from scipy import integrate
import matplotlib.pyplot as plt

def riemann(n = 50):
    rho = np.linspace(1, 2, n)
    print(rho)
    print(len(rho))
    # phi = np.linspace(0, np.pi/4, n)
    # theta = np.linspace(0, 2*np.pi, n)
    # f = lambda rho, phi, theta: rho**3 * np.sin(phi)
    # dr = 1/n
    # dp = np.pi/(4*n)
    # dt = 2*np.pi/n
    # dv = dr * dp * dt
    # sum = 0
    # for i in rho:
    #     r = i + np.random.rand()*dr
    #     for j in phi:
    #         p = j + np.random.rand()*dp
    #         for k in theta:
    #             sum += f(r, p, 0) *dv
    # print(sum)
riemann()

# f(rho, phi, theta) = rho^3*sin(phi).
def quad():
    f = lambda theta, phi, rho : rho**3 * np.sin(phi)
    ans,_ = integrate.tplquad(f, 1, 2, lambda x : 0, lambda x : np.pi/4, 
    lambda x, y: 0, lambda x, y : 2 * np.pi)
    return ans
quad3d = quad()
print(quad3d)

inp = open("out.txt", "r")
riemann = [np.float64(x) for x in inp.read().split()]

plt.style.use('seaborn-whitegrid')
n = np.linspace(10, 500, 50)

plt.plot(n, riemann, 'bo')
plt.hlines(y = quad3d, colors='r', linestyles='--', xmin = 0, xmax = 500 , linewidth = 2.0)

plt.show()

