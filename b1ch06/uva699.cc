#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

#define maxn 1000

int sum[maxn];

void build(int p) {
  int v;
  scanf("%d", &v);
  if (v == -1)
    return;
  sum[p] += v;
  build(p - 1);
  build(p + 1);
}

bool init(void) {
  int v;
  scanf("%d", &v);
  if (v == -1)
    return false;
  memset(sum, 0, sizeof(sum));
  int pos = maxn / 2;
  sum[pos] = v;
  build(pos - 1);
  build(pos + 1);
  return true;
}

int main(void) {
  int kase = 0;
  while (init()) {
    int p = 0;
    while (sum[p] == 0)
      p++;
    printf("Case %d:\n%d", ++kase, sum[p++]);
    while (sum[p] != 0)
      printf(" %d", sum[p++]);
    putchar('\n');
    putchar('\n');
  }
  return 0;
}
