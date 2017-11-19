#include <stdio.h>
#include <string.h>

#define MAXN 101000

char s[MAXN];
char t[MAXN];

int main(void) {

  while ((scanf("%s %s", s, t)) == 2) {
    int slen = strlen(s), tlen = strlen(t);

    int si = 0, ti = 0;
    while (si < slen) {
      while (ti < tlen && s[si] != t[ti])
        ti++;

      if (ti == tlen) {
        printf("No\n");
        break;
      } else {
        ti++;
        si++;
      }
    }
    if (si == slen)
      printf("Yes\n");
  }
  return 0;
}
