import numpy as np
f = lambda x : -1/3*(1000-x)**(-2/3)
for i in np.arange(9, 10.1, 0.1):
    print(f(i))