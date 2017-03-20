# System imports
from distutils.core import *
from distutils      import sysconfig

# Third-party modules - we depend on numpy for everything
import numpy

# Obtain the numpy include directory.  This logic works across numpy versions.
try:
    numpy_include = numpy.get_include()
except AttributeError:
    numpy_include = numpy.get_numpy_include()

# ezrange extension module
# Intel® Math Kernel Library Link Line Advisor | Intel® Software 
#   https://software.intel.com/en-us/articles/intel-mkl-link-line-advisor
_SwigMod = Extension("_SwigMod",
                   ["SwigMod.i","Main.cpp"],
                   swig_opts=['-c++', '-py3'],
                   include_dirs = [numpy_include, "D:\Program Files (x86)\IntelSWTools\compilers_and_libraries_2017.2.187\windows\mkl\include"],
                   library_dirs = ['D:\Program Files (x86)\IntelSWTools\compilers_and_libraries_2017.2.187\windows\mkl\lib\intel64_win',
                   'D:\Program Files (x86)\IntelSWTools\compilers_and_libraries_2017.2.187\windows\compiler\lib\intel64_win'],
                   libraries = ['mkl_core','mkl_intel_lp64','mkl_sequential','libiomp5md'],
                   )

# ezrange setup
setup(  name        = "SwigMod function",
        description = "Swiged Calc",
        author      = "Chachay",
        version     = "1.0",
        ext_modules = [_SwigMod]
        )
