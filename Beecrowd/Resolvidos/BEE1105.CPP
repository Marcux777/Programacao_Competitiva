#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX_B = 20;

int B, N;
int R[MAX_B + 5];
int D, C, V;

bool pode_pagar(void)
{
  for (int i = 0; i < N; i++)
  {
    D = C = 0;
    scanf("%d%d%d", &D, &C, &V);
    R[D - 1] -= V;
    R[C - 1] += V;
  }

  for (int i = 0; i < B; i++)
    if (R[i] < 0)
      return false;

  return true;
}

int main(void)
{
  // freopen("saida.txt", "w", stdout);
  while (scanf("%d%d", &B, &N), B || N)
  {
    for (int i = 0; i < B; i++)
      scanf("%d", &R[i]);

    printf("%c\n", pode_pagar() ? 'S' : 'N');
  }

  return 0;
}
