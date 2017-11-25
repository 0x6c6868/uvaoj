#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define maxn 100

char s[maxn];

int main(void) {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int len = strlen(s);
    int i = 0;
    int sum = 0;
    while (i < len) {
      char a = s[i];

      int b = 0;
      char c = '1';
      while (isdigit(c = s[++i])) {
        b *= 10;
        b += (c - '0');
      }

      if (b == 0)
        b = 1;

      switch (a) {
      case 'C':
        sum += b * 12010;
        break;
      case 'H':
        sum += b * 1008;
        break;
      case 'O':
        sum += b * 16000;
        break;
      case 'N':
        sum += b * 14010;
        break;
      }
    }
    printf("%.3f\n", sum / 1000.0);
  }

  return 0;
}
