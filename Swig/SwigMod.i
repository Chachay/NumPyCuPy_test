%module SwigMod

%{
    #define SWIG_FILE_WITH_INIT
    #include "SwigMod.h"
%}

%include "numpy.i"

%init %{
    import_array();
%}

%apply (double** ARGOUTVIEWM_ARRAY2, int* DIM1, int* DIM2){(double** outmat, int* mm, int* mn)}
%apply (int DIM1, int DIM2, double* IN_ARRAY2 ){(int mm1, int mn1, double* mat1),
                                                (int mm2, int mn2, double* mat2)}


%include "SwigMod.h"
