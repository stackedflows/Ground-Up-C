# using online tool to calculate base from basis
#e0 = (1-1000000)
#e1 = (01-100000)
#e2 = (001-10000)
#e3 = (0001-1000)
#e4 = (00001-100)
#e5 = (00000110)
#e6 = (-.5-.5-.5-.5-.5-.5-.5-.5)
#e7 = (000001-10)
# eigval RE = cos(PI/15)
# eigval IM = sin(PI/15)
# follows formula 1 - 6 here https://tamasgorbe.wordpress.com/2015/10/28/coxeter-projection-of-exceptional-root-systems/
#

import numpy as np
import matplotlib.pyplot as plt
import scipy.linalg as la

RE = np.array([
        [-0.25 , -0.25 , -0.25 , -0.25 , -0.25 , -0.75 , 0.25 , -0.25 ],
        [0.75 , -0.25 , -0.25 , -0.25 , -0.25 , 0.25 , 0.25 , -0.25 ],
        [-0.25 , 0.75 , -0.25 , -0.25 , -0.25 , 0.25 , 0.25 , -0.25 ],
        [-0.25 , -0.25 , 0.75 , -0.25 , -0.25 , 0.25 , 0.25 , -0.25 ],
        [-0.25 , -0.25 , -0.25 , 0.75 , -0.25 , 0.25 , 0.25 , -0.25 ],
        [-0.25 , -0.25 , -0.25 , -0.25 , 0.75 , 0.25 , 0.25 , -0.25 ],
        [-0.25 , -0.25 , -0.25 , -0.25 , -0.25 , 0.25 , -0.75 , -0.25 ],
        [-0.25 , -0.25 , -0.25 , -0.25 , -0.25 , 0.25 , 0.25 , 0.75]])


results = la.eig(RE)

print("eigenvals")
print(results[0])
print("eigenvects")
print(results[1])
