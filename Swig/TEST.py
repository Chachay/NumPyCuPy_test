import numpy as np
import _SwigMod as SwigMod

N = 3
# Generate NxN randomized matrix
ma = np.random.rand(N, N)
mb = np.random.rand(N, N)

print("6. Swig Simple Mult\n   ")
mc = SwigMod.Swig_Dot(ma,mb)
print(mc)

print("7. Swig MKL cblas_dgemm\n   ")
mc = SwigMod.Swig_Dot_MKL(ma,mb)
