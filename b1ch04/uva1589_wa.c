#include <stdio.h>
#include <string.h>

char board[10][9];
char boardbackup[10][9];

void print() {
  printf("-------------------\n");
  printf("|0|1|2|3|4|5|6|7|8|\n");
  for (int i = 0; i < 10; i++) {
    putchar('|');
    for (int j = 0; j < 9; j++) {
      putchar(boardbackup[i][j]);
      putchar('|');
    }
    printf("%d", i);
    putchar('\n');
  }
  printf("-------------------\n");
}

void markRG(int i, int j) {
  for (int x = i + 1; x < 10; x++) {
    if (board[x][j] == ' ' || board[x][j] == '1')
      board[x][j] = '1';
    else
      break;
  }
  for (int x = i - 1; x >= 0; x--) {
    if (board[x][j] == ' ' || board[x][j] == '1')
      board[x][j] = '1';
    else
      break;
  }
  for (int y = j + 1; y < 9; y++) {
    if (board[i][y] == ' ' || board[i][y] == '1')
      board[i][y] = '1';
    else
      break;
  }
  for (int y = j - 1; y >= 0; y--) {
    if (board[i][y] == ' ' || board[i][y] == '1')
      board[i][y] = '1';
    else
      break;
  }
}

void markH(int i, int j) {
  if (i - 2 >= 0 && j - 1 >= 0 &&
      (board[i - 1][j] == ' ' || board[i - 1][j] == '1'))
    board[i - 2][j - 1] = '1';
  if (i - 2 >= 0 && j + 1 <= 8 &&
      (board[i - 1][j] == ' ' || board[i - 1][j] == '1'))
    board[i - 2][j + 1] = '1';

  if (i - 1 >= 0 && j + 2 <= 8 &&
      (board[i][j + 1] == ' ' || board[i][j + 1] == '1'))
    board[i - 1][j + 2] = '1';
  if (i + 1 <= 9 && j + 2 <= 8 &&
      (board[i][j + 1] == ' ' || board[i][j + 1] == '1'))
    board[i + 1][j + 2] = '1';

  if (i + 2 <= 9 && j - 1 >= 0 &&
      (board[i + 1][j] == ' ' || board[i + 1][j] == '1'))
    board[i + 2][j - 1] = '1';
  if (i + 2 <= 9 && j + 1 <= 8 &&
      (board[i + 1][j] == ' ' || board[i + 1][j] == '1'))
    board[i + 2][j + 1] = '1';

  if (i - 1 >= 0 && j - 2 >= 0 &&
      (board[i][j - 1] == ' ' || board[i][j - 1] == '1'))
    board[i - 1][j - 2] = '1';
  if (i + 1 <= 9 && j - 2 >= 0 &&
      (board[i][j - 1] == ' ' || board[i][j - 1] == '1'))
    board[i + 1][j - 2] = '1';
}

void markC(int i, int j) {
  int flag = 0, flag_count = 0;
  for (int x = i + 1; x < 10; x++) {
    if (board[x][j] != ' ' && board[x][j] != '1') {
      flag = !flag;
      flag_count++;
    };
    if (flag && flag_count == 1 && board[x][j] == ' ')
      board[x][j] = '1';
  }

  flag = 0, flag_count = 0;
  for (int x = i - 1; x >= 0; x--) {
    if (board[x][j] != ' ' && board[x][j] != '1') {
      flag = !flag;
      flag_count++;
    };
    if (flag && flag_count == 1 && board[x][j] == ' ')
      board[x][j] = '1';
  }

  flag = 0, flag_count = 0;
  for (int y = j + 1; y < 9; y++) {
    if (board[i][y] != ' ' && board[i][y] != '1') {
      flag = !flag;
      flag_count++;
    };
    if (flag && flag_count == 1 && board[i][y] == ' ')
      board[i][y] = '1';
  }

  flag = 0, flag_count = 0;
  for (int y = j - 1; y >= 0; y--) {
    if (board[i][y] != ' ' && board[i][y] != '1') {
      flag = !flag;
      flag_count++;
    };
    if (flag && flag_count == 1 && board[i][y] == ' ')
      board[i][y] = '1';
  }
}

void mark() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 9; j++) {
      char t = board[i][j];
      if (t != ' ' && t != 'A' && t != '1') {
        switch (t) {
        case 'R':
          markRG(i, j);
          break;
        case 'H':
          markH(i, j);
          break;
        case 'C':
          markC(i, j);
          break;
        case 'G':
          markRG(i, j);
          break;
        }
      }
    }
  }
}

int check(int i, int j) {

  int ok = 0;

  memcpy(board, boardbackup, sizeof(boardbackup));
  if (j >= 4) {
    board[i][j - 1] = ' ';
    mark();
    if (board[i][j - 1] == ' ')
      ok = 1;
  }

  memcpy(board, boardbackup, sizeof(boardbackup));
  if (j <= 4) {
    board[i][j + 1] = ' ';
    mark();
    if (board[i][j + 1] == ' ')
      ok = 1;
  }

  memcpy(board, boardbackup, sizeof(boardbackup));
  if (i <= 1) {
    board[i + 1][j] = ' ';
    mark();
    if (board[i + 1][j] == ' ')
      ok = 1;
  }

  memcpy(board, boardbackup, sizeof(boardbackup));
  if (i >= 1) {
    board[i - 1][j] = ' ';
    mark();
    if (board[i - 1][j] == ' ')
      ok = 1;
  }
  return ok;
}

int main(void) {
  int n, x, y;
  while (scanf("%d%d%d", &n, &x, &y) == 3 && n != 0) {
    memset(boardbackup, ' ', sizeof(boardbackup));
    for (int i = 0; i < n; i++) {
      getchar(); // 过滤换行
      char a;
      int b, c;
      scanf("%c%d%d", &a, &b, &c);
      boardbackup[b - 1][c - 1] = a;
    }
    printf("%s\n", check(x - 1, y - 1) ? "NO" : "YES");
  }
  return 0;
}