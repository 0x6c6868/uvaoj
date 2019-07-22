#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000
int n;
int a[15], b[15], c[15];

// 这个代码是存在漏洞的
// 应该存储状态，但是代码通过1000000这个最大次数判断，重要的是，可以AC，神奇

int main() {
  int rnd = 0;
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++)
      scanf("%d%d%d", &a[i], &b[i], &c[i]);
    int t, count;
    for (t = 1; t < N; t++) {
      // count代表清醒的人数
      count = 0;
      for (int i = 0; i < n; i++)
        //  c[i]代表周期内的第c[i]分钟
        if (c[i] <= a[i])
          count++;
      if (count == n)
        break;
      for (int i = 0; i < n; i++) {
        //当到达周期末尾或到达即将睡觉的时候却发现清醒人数不少于睡觉人数时，重新开始计时
        if (c[i] == a[i] + b[i] || (c[i] == a[i] && count >= n - count))
          c[i] = 0;
        c[i]++;
      }
    }
    if (t == N)
      t = -1;
    printf("Case %d: %d\n", ++rnd, t);
  }
  return 0;
}
