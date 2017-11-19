#include <stdio.h>
#include <string.h>

int main(void) {

  int T = 0;
  int a, b;
  while (scanf("%d", &a)) {
    if (a == 0)
      break;

    scanf("%d\n", &b);

    int m[a][b];
    memset(m, 0, sizeof(m));
    int t = 0;
    char s[a][b];
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        s[i][j] = getchar();

        if (s[i][j] == '*')
          continue;

        if (i < 1 || s[i - 1][j] == '*' || j < 1 || s[i][j - 1] == '*') {
          m[i][j] = ++t;
        }
      }
      getchar();
    }

    if (T != 0)
      putchar('\n');
    printf("puzzle #%d:\n", ++T);

    printf("Across\n");
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if (m[i][j] != 0) {

          printf("%3d.", m[i][j]);
          while (j < b) {
            if (s[i][j] != '*') {
              putchar(s[i][j++]);
            } else {
              break;
            }
          }
          putchar('\n');
        }
      }
    }

    printf("Down\n");
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if (m[i][j] != 0) {

          if (i > 0 && s[i - 1][j] != '*')
            continue;

          printf("%3d.", m[i][j]);
          int tmp_i = i;
          while (tmp_i < a) {
            if (s[tmp_i][j] != '*') {
              putchar(s[tmp_i++][j]);
            } else {
              break;
            }
          }
          putchar('\n');
        }
      }
    }
  }
  return 0;
}
