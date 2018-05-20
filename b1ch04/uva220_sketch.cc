#include <stdio.h>

char tmp[8][8];
char next_move;

void print_tmp() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++)
      putchar(tmp[i][j]);
    putchar('\n');
  }
}

void count_tmp() {
  int b_num = 0;
  int w_num = 0;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      if (tmp[i][j] == 'W') {
        w_num++;
      } else if (tmp[i][j] == 'B') {
        b_num++;
      }
    }

  printf("Black - %d White - %d\n", b_num, w_num);
}

int check(int x, int y) {
  // TODO
  return 0;
}

void play(int x, int y) {
  // TODO
}

void l_op() {
  int flag = 1;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (check(i, j)) {
        printf("(%d,%d)", i + 1, j + 1);
        flag = 0;
      }
    }
  }
  if (flag) {
    printf("No legal move.");
  }
  putchar('\n');
}

void m_op(int x, int y) {
  // 游戏无法继续则切换游戏者
  if (!check(x, y)) {
    next_move = next_move == 'B' ? 'W' : 'B';
  }

  play(x, y);
  count_tmp();
}

int main(void) {

  int n = 0;
  if (scanf("%d", &n) == 1 && n) {

    for (int x = 0; x < n; x++) {
      for (int i = 0; i < 8; i++) {
        getchar(); // 处理换行
        for (int j = 0; j < 8; j++) {
          tmp[i][j] = getchar();
        }
      }
      print_tmp();

      getchar(); // 处理换行
      next_move = getchar();

      char next_op = ' ';
      while (next_op != 'Q') {
        switch (next_op) {
        case 'L':
          l_op();
          break;
        case 'M': {
          int param;
          scanf("%d", &param);
          m_op(param / 10 - 1, param % 10 - 1);
        } break;
        }

        getchar(); // 处理换行
        next_op = getchar();
      }
    }
  }
  return 0;
}
