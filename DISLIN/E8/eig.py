import numpy as np
import scipy.linalg as la

roots = [[1,-1,0,0,0,0,0,0],
        [0,1,-1,0,0,0,0,0],
        [0,0,1,-1,0,0,0,0],
        [0,0,0,1,-1,0,0,0],
        [0,0,0,0,1,-1,0,0],
        [0,0,0,0,0,1,-1,0],
        [0,0,0,0,0,1,1,0],
        [-.5,-.5,-.5,-.5,-.5,-.5,-.5,-.5]]

Id = [[1,0,0,0,0,0,0,0],
        [0,1,0,0,0,0,0,0],
        [0,0,1,0,0,0,0,0],
        [0,0,0,1,0,0,0,0],
        [0,0,0,0,1,0,0,0],
        [0,0,0,0,0,1,0,0],
        [0,0,0,0,0,0,1,0],
        [0,0,0,0,0,0,0,1]]


def prod(R_list):
        out = np.array(Id)
        for i in range(len(R_list)):
                mat = np.array(Id - R_list[i])
                out = np.matmul(out, mat)
        return np.array(out)

def alpha_alphaT(a):
        np_a = np.array(a)
        aaT = np.outer(np_a,np_a)
        return np.array(aaT)

RC_L = []

for i in range(len(roots)):
        RC_L.append(np.array(alpha_alphaT(roots[i])))

RC = prod(RC_L)

print(RC)

results = la.eig(RC)

print("eigenvals")
print(results[0])
print("eigenvects")
print(results[1])
