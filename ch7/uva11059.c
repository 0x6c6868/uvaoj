#include <stdio.h>

#define bool int
#define true 1
#define false 0

int main(void) {

  int n;
  int kase = 0;
  while (scanf("%d", &n) == 1 && n) {
    int t[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &t[i]);
    }

    long long int rst = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        long long int tt = 1;
        for (int x = i; x <= j; x++)
          tt *= t[x];
        rst = tt > rst ? tt : rst;
      }
    }
    printf("Case #%d: The maximum product is %lld.\n\n", ++kase, rst);
  }
  return 0;
}
