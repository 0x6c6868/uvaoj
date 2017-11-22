#include <stdio.h>

int main(void) {
  int T;
  scanf("%d", &T);

  while (T--) {
    int n, len;
    scanf("%d %d", &n, &len);

    char s[n][len + 1];
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }

    int score = 0;
    for (int j = 0; j < len; j++) {
      int A_c = 0, C_c = 0, G_c = 0, T_c = 0;
      for (int i = 0; i < n; i++) {
        if (s[i][j] == 'A')
          A_c++;
        if (s[i][j] == 'C')
          C_c++;
        if (s[i][j] == 'G')
          G_c++;
        if (s[i][j] == 'T')
          T_c++;
      }
      if (A_c >= C_c && A_c >= G_c && A_c >= T_c) {
        putchar('A');
        score += C_c + G_c + T_c;
      } else if (C_c >= G_c && C_c >= T_c) {
        putchar('C');
        score += A_c + G_c + T_c;
      } else if (G_c >= T_c) {
        putchar('G');
        score += A_c + C_c + T_c;
      } else {
        putchar('T');
        score += A_c + C_c + G_c;
      }
    }
    printf("\n%d\n", score);
  }
  return 0;
}
