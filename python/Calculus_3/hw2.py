import numpy as np
import scipy.integrate as integrate
import matplotlib.pyplot as plt


# f1 = lambda x, y : np.float64(1/(x+y)**3)

# f = lambda x, y : np.float64(1/(x+y)**3) if x >= 1 and y >= 1 and x+y <= 3 else 0
f = lambda x, y : x+y


a = 0
b = 1
c = lambda x: (1-np.sqrt(x))**2
d = lambda x: np.sqrt(1-x**2)
A,_ = integrate.dblquad(f, a, b, c, d)
print(A)

# def minhhoa():
#     mx = 100
#     x_list = np.linspace(1, 2, mx)
#     y_list = np.linspace(1, 2, mx)

#     X, Y = np.meshgrid(x_list, y_list)
#     Z = f1(X, Y)

#     ax = plt.axes(projection='3d')

#     ax.plot_surface(X, Y, Z, rstride=1, cstride=1,
#                 cmap='viridis', edgecolor='none')
    
#     ax.view_init(60, 35)
    
#     plt.show()

# minhhoa()

# def riemann(a, b, c, d, n):
#     x = np.linspace(a, b, n)
#     y = np.linspace(c, d, n)
#     dx = (b-a)/n
#     dy = (d-c)/n
#     dA = dx * dy
    
#     ans = 0
#     for i in x:
#         for j in y:
#             xi = i + np.random.ranf()/n
#             yi = j + np.random.ranf()/n
#             ans += f(xi, yi)*dA
            
#     return ans

# print(riemann(1, 2, 1, 2, 50))

# f = lambda x, y : np.float64(1/(x+y)**3) if x >= 1 and y >= 1 and x+y <= 3 else 0

# def hoitu():
#     global A
#     n = np.linspace(10, 200, 20)
#     R = [riemann(1, 2, 1, 2, int(i)) for i in n]

#     plt.style.use('seaborn-whitegrid')
#     plt.plot(n, R, 'bo')
#     plt.hlines(y = A, colors='r', linestyles='--', xmin = 0, xmax = 200 , linewidth = 2.0)
    
#     plt.show()

# hoitu()