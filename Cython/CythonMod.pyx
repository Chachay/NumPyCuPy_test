# -*- coding: utf-8 -*-
cimport numpy as np
cimport cython
import numpy as np

@cython.boundscheck(False) # turn off bounds-checking for entire function
@cython.wraparound(False)  # turn off negative index wrapping for entire function

cpdef np.ndarray Cy_NpDot(np.ndarray a, np.ndarray b):
    return np.dot(a, b)
    
cpdef np.ndarray Cy_Dot(np.ndarray a, np.ndarray b):
    cdef np.ndarray c
    c = np.zeros((a.shape[0], b.shape[0]))
    for i in range(a.shape[0]):
        for j in range(b.shape[1]):
            for k in range(a.shape[1]):
                c[i][j] += a[i][k] * b[k][j]
    return c
