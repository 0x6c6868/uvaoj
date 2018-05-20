/**
 * http://blog.csdn.net/crazysillynerd/article/details/43339157
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

int main() {
  double M[20][40];
  long long E[20][40];

  for (int i = 0; i <= 9; ++i)
    for (int j = 1; j <= 30; ++j) {
      double m = 1 - pow(2, -1 - i), e = pow(2, j) - 1;

      double t = log10(m) + e * log10(2);
      E[i][j] = t, M[i][j] = pow(10, t - E[i][j]);
    }

  char s[100];
  while (scanf("%s", s) == 1 && strcmp(s, "0e0")) {

    for (int i = 0; i < strlen(s); i++) {
      if (s[i] == 'e') {
        s[i] = ' ';
        break;
      }
    }

    double A;
    int B;
    sscanf(s, "%lf%d", &A, &B);

    while (A < 1)
      A *= 10, B -= 1;

    for (int i = 0; i <= 9; ++i)
      for (int j = 1; j <= 30; ++j) {
        if (B == E[i][j] &&
            (fabs(A - M[i][j]) < 1e-4 || fabs(A / 10 - M[i][j]) < 1e-4)) {
          printf("%d %d\n", i, j);
          break;
        }
      }
  }
}