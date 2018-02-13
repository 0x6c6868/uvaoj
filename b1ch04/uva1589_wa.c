// 对拍程序

// import random

// choices = ["R", "H", "C"]

// for _ in range(5000):
//     n = random.randint(2, 7)
//     x, y = random.randint(1, 3), random.randint(4, 6)

//     g_x, g_y = random.randint(8, 10), random.randint(4, 6)

//     print(n, x, y)
//     print("G", g_x, g_y)

//     tmpList = []
//     while n > 1:
//         tmp = random.choice(choices)
//         tmpx, tmpy = random.randint(1, 10), random.randint(1, 9)
//         if (tmpx == x and tmpy == y) or (tmpx == g_x and tmpy == y) or (tmpx,
//         tmpy) in tmpList:
//             continue

//         tmpList.append((tmpx, tmpy))

//         n -= 1

//         print(tmp, tmpx, tmpy)

// print(0, 0, 0)

// AC的代码

// #include <iostream>
// #include <stdio.h>
// #include <string.h>
// using namespace std;
// char cb[12][10], ab[12][10];
// void RG(int a, int b) {
//   int c;
//   for (c = a - 1; c >= 1; c--) {
//     ab[c][b] = 'S';
//     if (cb[c][b] != 'A' && cb[c][b] != 'B')
//       break;
//   }
//   for (c = a + 1; c <= 3; c++) {
//     ab[c][b] = 'S';
//     if (cb[c][b] != 'A' && cb[c][b] != 'B')
//       break;
//   }
//   for (c = b + 1; c <= 9; c++) {
//     ab[a][c] = 'S';
//     if (cb[a][c] != 'A' && cb[a][c] != 'B')
//       break;
//   }
//   for (c = b - 1; c >= 1; c--) {
//     ab[a][c] = 'S';
//     if (cb[a][c] != 'A' && cb[a][c] != 'B')
//       break;
//   }
// }
// void H(int a, int b) {
//   if (cb[a][b + 1] == 'A' && b + 2 <= 9 && a - 1 >= 1)
//     ab[a - 1][b + 2] = 'S';
//   if (cb[a][b + 1] == 'A' && b + 2 <= 9 && a + 1 < 11)
//     ab[a + 1][b + 2] = 'S';
//   if (cb[a][b - 1] == 'A' && b - 2 >= 1 && a - 1 >= 1)
//     ab[a - 1][b - 2] = 'S';
//   if (cb[a][b - 1] == 'A' && b - 2 >= 1 && a + 1 < 11)
//     ab[a + 1][b - 2] = 'S';
//   if (cb[a + 1][b] == 'A' && b - 1 >= 1 && a + 2 < 11)
//     ab[a + 2][b - 1] = 'S';
//   if (cb[a + 1][b] == 'A' && b + 1 <= 9 && a + 2 < 11)
//     ab[a + 2][b + 1] = 'S';
//   if (cb[a - 1][b] == 'A' && b - 1 >= 1 && a - 2 >= 1)
//     ab[a - 2][b - 1] = 'S';
//   if (cb[a - 1][b] == 'A' && b + 1 <= 9 && a - 2 >= 1)
//     ab[a - 2][b + 1] = 'S';
// }
// void C(int a, int b) {
//   if (b >= 4 && b <= 6 && a == 1)
//     if (cb[2][b] != 'A' && cb[2][b] != 'B')
//       ab[3][b] = 'S';
//   int c, d;
//   for (c = a - 1; c >= 1; c--) {
//     if (cb[c][b] == 'B')
//       return;
//     if (cb[c][b] != 'A')
//       break;
//   }
//   for (d = c - 1; d >= 1; d--) {
//     ab[d][b] = 'S';
//     if (cb[d][b] != 'A' && cb[d][b] != 'B')
//       break;
//   }
//   for (c = b + 1; c <= 9; c++) {
//     if (cb[a][c] == 'B')
//       return;
//     if (cb[a][c] != 'A')
//       break;
//   }
//   for (d = c + 1; d <= 9; d++) {
//     ab[a][d] = 'S';
//     if (cb[a][d] != 'A' && cb[a][d] != 'B')
//       break;
//   }
//   for (c = b - 1; c >= 1; c--) {
//     if (cb[a][c] == 'B')
//       return;
//     if (cb[a][c] != 'A')
//       break;
//   }
//   for (d = c - 1; d >= 1; d--) {
//     ab[a][d] = 'S';
//     if (cb[a][d] != 'A' && cb[a][d] != 'B')
//       break;
//   }
// }
// int judge(int i, int j) {
//   int ok = 1;
//   if (i + 1 < 4 && ab[i + 1][j] != 'S')
//     ok = 0;
//   if (i - 1 > 0 && ab[i - 1][j] != 'S')
//     ok = 0;
//   if (j + 1 < 7 && ab[i][j + 1] != 'S')
//     ok = 0;
//   if (j - 1 > 3 && ab[i][j - 1] != 'S')
//     ok = 0;
//   return ok;
// }
// int main(void) {
//   int n, i, j, Ch[8][3], a1, b1;
//   while (cin >> n >> a1 >> b1 && n && a1 && b1) {
//     memset(cb, 'A', sizeof(cb));
//     memset(ab, 'A', sizeof(ab));
//     memset(Ch, 0, sizeof(Ch));
//     cb[a1][b1] = 'B';
//     char ch;
//     for (int k = 0; k < n; k++) {
//       cin >> ch >> i >> j;
//       cb[i][j] = ch;
//       Ch[k][0] = i;
//       Ch[k][1] = j;
//     }
//     for (int m = 0; m < n; m++) {
//       int a = Ch[m][0], b = Ch[m][1];
//       if (cb[a][b] == 'R' || cb[a][b] == 'G')
//         RG(a, b);
//       else if (cb[a][b] == 'H')
//         H(a, b);
//       else if (cb[a][b] == 'C')
//         C(a, b);
//     }
//     puts(judge(a1, b1) ? "YES" : "NO");
//   }
//   return 0;
// }

#include <stdio.h>
#include <string.h>

char board[10][9];
char boardbackup[10][9];

void print_board() {
  printf("-------------------\n");
  printf("|0|1|2|3|4|5|6|7|8|\n");
  for (int i = 0; i < 10; i++) {
    putchar('|');
    for (int j = 0; j < 9; j++) {
      putchar(board[i][j]);
      putchar('|');
    }
    printf("%d", i);
    putchar('\n');
  }
  printf("-------------------\n");
}

void print_boardbackup() {
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
      (board[i - 1][j] == ' ' || board[i - 1][j] == '1') &&
      (board[i - 2][j - 1] == ' ' || board[i - 2][j - 1] == '1'))
    board[i - 2][j - 1] = '1';

  if (i - 2 >= 0 && j + 1 <= 8 &&
      (board[i - 1][j] == ' ' || board[i - 1][j] == '1') &&
      (board[i - 2][j + 1] == ' ' || board[i - 2][j + 1] == '1'))
    board[i - 2][j + 1] = '1';

  if (i - 1 >= 0 && j + 2 <= 8 &&
      (board[i][j + 1] == ' ' || board[i][j + 1] == '1') &&
      (board[i - 1][j + 2] == ' ' || board[i - 1][j + 2] == '1'))
    board[i - 1][j + 2] = '1';

  if (i + 1 <= 9 && j + 2 <= 8 &&
      (board[i][j + 1] == ' ' || board[i][j + 1] == '1') &&
      (board[i + 1][j + 2] == ' ' || board[i + 1][j + 2] == '1'))
    board[i + 1][j + 2] = '1';

  if (i + 2 <= 9 && j - 1 >= 0 &&
      (board[i + 1][j] == ' ' || board[i + 1][j] == '1') &&
      (board[i + 2][j - 1] == ' ' || board[i + 2][j - 1] == '1'))
    board[i + 2][j - 1] = '1';

  if (i + 2 <= 9 && j + 1 <= 8 &&
      (board[i + 1][j] == ' ' || board[i + 1][j] == '1') &&
      (board[i + 2][j + 1] == ' ' || board[i + 2][j + 1] == '1'))
    board[i + 2][j + 1] = '1';

  if (i - 1 >= 0 && j - 2 >= 0 &&
      (board[i][j - 1] == ' ' || board[i][j - 1] == '1') &&
      (board[i - 1][j - 2] == ' ' || board[i - 1][j - 2] == '1'))
    board[i - 1][j - 2] = '1';

  if (i + 1 <= 9 && j - 2 >= 0 &&
      (board[i][j - 1] == ' ' || board[i][j - 1] == '1') &&
      (board[i + 1][j - 2] == ' ' || board[i + 1][j - 2] == '1'))
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
          // print_board();
          break;
        case 'H':
          markH(i, j);
          // print_board();
          break;
        case 'C':
          markC(i, j);
          // print_board();
          break;
        case 'G':
          markRG(i, j);
          // print_board();
          break;
        }
      }
    }
  }
}

int check(int i, int j) {

  memcpy(board, boardbackup, sizeof(boardbackup));
  // 左移一步
  if (j >= 4) {
    // 吃子
    board[i][j - 1] = ' ';
    mark();
    if (board[i][j - 1] == ' ')
      return 1;
  }

  memcpy(board, boardbackup, sizeof(boardbackup));
  // 右移一步
  if (j <= 4) {
    // 吃子
    board[i][j + 1] = ' ';
    mark();
    if (board[i][j + 1] == ' ')
      return 1;
  }

  memcpy(board, boardbackup, sizeof(boardbackup));
  // 下移一步
  if (i <= 1) {
    // 吃子
    board[i + 1][j] = ' ';
    mark();
    if (board[i + 1][j] == ' ')
      return 1;
  }

  memcpy(board, boardbackup, sizeof(boardbackup));
  // 上移一步
  if (i >= 1) {
    // 吃子
    board[i - 1][j] = ' ';
    mark();
    if (board[i - 1][j] == ' ')
      return 1;
  }

  return 0;
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
    // print_boardbackup();
    printf("%s\n", check(x - 1, y - 1) ? "NO" : "YES");
  }
  return 0;
}