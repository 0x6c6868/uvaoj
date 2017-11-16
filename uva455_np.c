#include <stdio.h>
#include <string.h>

#define maxn 100

int check(char *s, int len, int p) {
  if (len % p)
    return 0;

  for (int i = p; i < len; i++) {
    if (s[i] != s[i % p])
      return 0;
  }
  return 1;
}

int main(void) {

  int T;
  scanf("%d", &T);
  while (T--) {
    char s[maxn];
    scanf("%s", s);

    int len = strlen(s);
    for (int i = 1; i < len; i++) {
      if (check(s, len, i)) {
        printf("%d", i);
        break;
      }
    }
    if (T)
      putchar('\n');
  }

  return 0;
}
