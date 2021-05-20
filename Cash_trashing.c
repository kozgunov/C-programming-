#include <stdio.h>
#include <time.h>

#define N 10000
float m[N][N];

int main()
{
  float a = 0.0;

  clock_t start, finish;
  start = clock();

  for(int n = 0; n < 100; ++n)
    for(int i = 0; i < N; ++i)
      for(int j = 0; j < N; ++j)
        a += m[j][i];

  finish = clock();

  printf("%f: %f ms\n", a, ((double)(finish - start)) * 1000.0 / CLOCKS_PER_SEC);

  return 0;
}

// 9216 Kb
