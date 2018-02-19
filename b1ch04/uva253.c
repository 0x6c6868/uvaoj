#include <stdio.h>

char s[13];
int oper[6][6] = {{0, 1, 2, 3, 4, 5}, {1, 5, 2, 3, 0, 4}, {2, 1, 5, 0, 4, 3},
                  {3, 1, 0, 5, 4, 2}, {4, 0, 2, 3, 5, 1}, {5, 4, 2, 3, 1, 0}};

int check(int x) {
  char tmp[6] = {0};

  // 以x为顶点，初始化
  for (int i = 0; i < 6; i++) {
    tmp[i] = s[oper[x][i]];
  }

  // 旋转四次
  for (int i = 0; i < 4; i++) {

    char t = tmp[1];
    tmp[1] = tmp[2];
    tmp[2] = tmp[4];
    tmp[4] = tmp[3];
    tmp[3] = t;

    int flag = 1;
    for (int j = 0; j < 6; j++) {
      if (tmp[j] != s[j + 6])
        flag = 0;
    }
    if (flag)
      return 1;
  }

  return 0;
}

int main(void) {
  while (scanf("%s", s) == 1) {

    int ok = 0;
    for (int i = 0; i < 6; i++) {
      if (check(i)) {
        ok = 1;
        break;
      }
    }
    printf("%s\n", ok ? "TRUE" : "FALSE");
  }
  return 0;
}