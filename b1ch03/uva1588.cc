#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define maxn 10000

char a[maxn];
char b[maxn];

bool check(int x, int y, int alen, int blen, char ax, char by) {
  if (x > alen || y > blen)
    return true;
  if (((ax - '0') + (by - '0')) <= 3)
    return true;
  return false;
}

int Do(char a[], char b[]) {

  int rst = 0;
  int alen = strlen(a);
  int blen = strlen(b);

  for (int i = 0; i <= alen; i++) {
    int x = i;
    int y = 0;
    while (y < blen && check(x, y, alen, blen, a[x], b[y])) {
      x++;
      y++;
    }

    if (y == blen) {
      rst += (blen + i) > alen ? i + blen : alen;
      break;
    }
  }
  return rst;
}

int main(void) {
  while (scanf("%s\n%s", a, b) == 2) {
    int rsta = Do(a, b);
    int rstb = Do(b, a);
    printf("%d\n", rsta > rstb ? rstb : rsta);
  }
  return 0;
}