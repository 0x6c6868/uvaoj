#include <iostream>
unsigned N, A, B, Sp, Sq, ansA, ansB;
unsigned long long Pofs, K, nowK;
int main() {
  while (scanf("%u%u%u", &N, &Sp, &Sq) != -1) {
    K = 0xffffffffffffffff;
    for (A = 0; A < 32; ++A)
      for (B = 0; B < 32; ++B) {
        Pofs = (N - 1) * Sp;
        nowK = ((Pofs + (Pofs << A)) >> B) + Sq;
        if (nowK >= N * Sq && nowK < K)
          K = nowK, ansA = A, ansB = B;
      }
    printf("%llu %u %u\n", K, ansA, ansB);
  }
  return 0;
}