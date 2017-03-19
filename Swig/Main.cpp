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
    // dgemmでエラーでる. リンカの問題？
    // とりあえずmkl_mallocの問題でないことを確認するためmat1は計算に使わない
    double *A, *B, *C;
    double alpha = 1.0;
    double beta = 0.0;
    A = (double *)mkl_malloc( mn1*mm1*sizeof( double ), 64 );
    B = (double *)mkl_malloc( mn2*mm2*sizeof( double ), 64 );
    C = (double *)mkl_malloc( mm1*mn2*sizeof( double ), 64 );
    
    cout << mm1 << mn1 << mm2 << mn2 <<endl;

    // Multiplying matrix a and b and storing in array mult.
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                mm1, mn2, mn1, alpha, A, mn1, B, mn2, beta, C, mn2);
    *mm = mm1;
    *mn = mn2;
    *outmat = C;
    
    mkl_free(A);
    mkl_free(B);
}
#endif
