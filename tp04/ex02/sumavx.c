#include <stdlib.h>
#include <stdio.h>
#include <immintrin.h>

#define N 10000000

static inline float _mm256_reduce_add_ps(__m256 x) {
    const __m128 x128 = _mm_add_ps(_mm256_extractf128_ps(x, 1), _mm256_castps256_ps128(x));
    const __m128 x64 = _mm_add_ps(x128, _mm_movehl_ps(x128, x128));
    const __m128 x32 = _mm_add_ss(x64, _mm_shuffle_ps(x64, x64, 0x55));
    return _mm_cvtss_f32(x32);
}

float cmp_sum(float vecn[] , unsigned n)
{
    const unsigned offset = n%8u;
    n = (n<offset) ? 0 : (n-offset);
    
    __m256 acc = _mm256_setzero_ps();
        
    for(unsigned i=0; i<n-8; i+=8)
    {
        __m256 tmp = _mm256_load_ps(&vecn[i]);
        acc = _mm256_add_ps(acc, tmp);
    } 

    float x = _mm256_reduce_add_ps(acc);
    for(unsigned i=n; i<offset+n; i++)
        x+=vecn[i]; 
    return x;
}

int main()
{
    float* vecn;
    posix_memalign((void**)&vecn, 32, sizeof(float)*N);
    
    for(unsigned i=0; i<N; i++)
        vecn[i] = i*0.37f; 

    printf("Sumatoria: %f\n", cmp_sum(vecn, N));
    free(vecn);
    return 0;
}
