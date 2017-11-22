#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

char rst[5][5];
int si = 0, sj = 0;
bool err = false;

bool _do(char c) {
  switch (c) {
  case 'A':
    if (si == 0)
      return false;
    rst[si][sj] = rst[si - 1][sj];
    rst[--si][sj] = ' ';
    break;
  case 'B':
    if (si == 4)
      return false;
    rst[si][sj] = rst[si + 1][sj];
    rst[++si][sj] = ' ';
    break;
  case 'L':
    if (sj == 0)
      return false;
    rst[si][sj] = rst[si][sj - 1];
    rst[si][--sj] = ' ';
    break;
  case 'R':
    if (sj == 4)
      return false;
    rst[si][sj] = rst[si][sj + 1];
    rst[si][++sj] = ' ';
    break;
  }
  return true;
}

int main(void) {
  int T = 0;
  while (1) {
    memset(rst, ' ', sizeof(rst));
    si = 0, sj = 0;
    err = false;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        rst[i][j] = getchar();

        if (rst[i][j] == ' ')
          si = i, sj = j;

        if (i == 0 && j == 0 && rst[i][j] == 'Z') {
          return 0;
        }
        if (j == 4 && rst[i][j] == '\n') {
          rst[i][j] = ' ';
          si = i, sj = j;
        } else if (j == 4) {
          getchar();
        }
      }
    }
    char c;
    while ((c = getchar()) != '0') {
      if (c == '\n')
        continue;
      if (!_do(c)) {
        err = true;
      }
    }
    getchar(); // 处理换行
    if (T != 0)
      putchar('\n');
    printf("Puzzle #%d:\n", ++T);
    if (err) {
      printf("This puzzle has no final configuration.\n");
    } else {
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          putchar(rst[i][j]);
          if (j != 4)
            putchar(' ');
        }
        putchar('\n');
      }
    }
  }
}
