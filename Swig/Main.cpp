#ifndef __MAIN_CPP
#define __MAIN_CPP

#include <stdlib.h>
#include "SwigMod.h"
#include "mkl.h"

#include <iostream>
using namespace std;

void Swig_Dot(int mm1, int mn1, double* mat1,
              int mm2, int mn2, double* mat2,
              double** outmat, int* mm, int* mn)
{
    double* arr = NULL;
    arr = (double*)calloc(mm1 * mn2, sizeof(double));
    
    // Multiplying matrix a and b and storing in array mult.
    for(int i = 0; i < mm1; ++i)
        for(int j = 0; j < mn2; ++j)
            for(int k = 0; k < mn1; ++k)
                arr[i*mn2+j] += mat1[i*mn1+k] * mat2[k*mn2+j];
    *mm = mm1;
    *mn = mn2;
    *outmat = arr;
}

void Swig_Dot_MKL(int mm1, int mn1, double* mat1,
              int mm2, int mn2, double* mat2,
              double** outmat, int* mm, int* mn)
{
    double alpha = 1.0;
    double beta = 0.0;

    double *C = (double *)mkl_malloc( mm1*mn2*sizeof( double ), 64 );
    if (C == NULL) {
        printf( "\n ERROR: Can't allocate memory for matrices. Aborting... \n\n");
        mkl_free(C);
        return;
    }

    for (int i = 0; i < (mm1*mn2); i++) {
        C[i] = 0.0;
    }
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                mm1, mn2, mn1, alpha, mat1, mn1, mat2, mn2, beta, C, mn2);

    double *res = (double *)malloc( mm1*mn2*sizeof( double ));
    memcpy(res, C, mm1*mn2*sizeof( double ));
    *mm = mm1;
    *mn = mn2;
    *outmat = res;
    mkl_free(C);
}
#endif
