#include <stdio.h>
#include <string.h>

#define MAXN 100

int check(char s[], int len, int p) {
  int c = len / p;
  if (len % p)
    return 0;

  for (int i = 1; i < c; i++) {
    for (int j = 0; j < p; j++) {
      if (s[j] != s[i * p + j])
        return 0;
    }
  }
  return 1;
}

int main(void) {
  int T;

  scanf("%d", &T);
  while (T--) {
    char s[MAXN];
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 1; i <= len; i++) {
      if (check(s, len, i)) {
        printf("%d\n", i);
        break;
      }
    }
    if (T) {
      printf("\n");
    }
  }
  return 0;
}