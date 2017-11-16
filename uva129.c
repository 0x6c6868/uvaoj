#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

int s[100];
int n, l, num;

bool judge(int cur) {
  int j, k;
  for (j = 1; j * 2 <= cur + 1; j++) {
    bool flag = true;
    for (k = 0; k < j; k++)
      if (s[cur - k] != s[cur - k - j]) {
        flag = false;
        break;
      }
    if (flag)
      return (false);
  }
  return (true);
}

void output(int cur) {
  for (int i = 0; i <= cur; i++) {
    if (i % 4 == 0 && i > 0) {
      if (i % 64 == 0 && i > 0)
        putchar('\n');
      else
        putchar(' ');
    }
    putchar(s[i]);
  }
  printf("\n%d\n", cur + 1);
}

bool dfs(int cur) {
  int i;
  for (i = 0; i < l; i++) {
    s[cur] = 'A' + i;
    if (judge(cur)) {
      num++;
      if (num == n) {
        output(cur);
        return (true);
      }
      if (dfs(cur + 1))
        return (true);
    }
  }
  return (false);
}

int main() {
  while (scanf("%d%d", &n, &l) == 2 && n + l) {
    num = 0;
    dfs(0);
  }
}
