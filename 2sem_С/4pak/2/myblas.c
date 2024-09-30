#include <stdio.h>

void cblas_dgemm(int Layout, int transa, int transb, int m, int n, int k,
                int alpha, const double *A, int lda, const double *B, int ldb, 
                double beta, double *C, int ldc)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for (int l = 0; l < k; l++)
            {
                C[i * n + j] += A[i * k + l] * B[l * n + j] * alpha;
            }
        }
    }
}
