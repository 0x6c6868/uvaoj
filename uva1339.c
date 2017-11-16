#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100

int char_2_int(char ch) { return ch - 'A'; }

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main(void) {

  char a[MAXN], b[MAXN];

  while (scanf("%s", a) == 1 && scanf("%s", b) == 1) {
    int acnt[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int bcnt[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int alen = strlen(a), blen = strlen(b);
    for (int i = 0; i < alen; i++) {
      acnt[char_2_int(a[i])]++;
    }
    for (int i = 0; i < blen; i++) {
      bcnt[char_2_int(b[i])]++;
    }

    qsort(acnt, 26, sizeof(int), cmp);
    qsort(bcnt, 26, sizeof(int), cmp);

    int i;
    for (i = 0; i < 26; i++) {
      if (acnt[i] != bcnt[i]) {
        printf("NO\n");
        break;
      }
    }
    if (i == 26)
      printf("YES\n");
  }
  return 0;
}
