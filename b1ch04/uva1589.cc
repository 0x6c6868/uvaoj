// https://blog.csdn.net/qiweigo/article/details/43445397

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char cb[12][10], ab[12][10];

void RG(int a, int b) {
  int c;
  for (c = a - 1; c >= 1; c--) {
    ab[c][b] = 'S';
    if (cb[c][b] != 'A' && cb[c][b] != 'B')
      break;
  }
  for (c = a + 1; c <= 3; c++) {
    ab[c][b] = 'S';
    if (cb[c][b] != 'A' && cb[c][b] != 'B')
      break;
  }
  for (c = b + 1; c <= 9; c++) {
    ab[a][c] = 'S';
    if (cb[a][c] != 'A' && cb[a][c] != 'B')
      break;
  }
  for (c = b - 1; c >= 1; c--) {
    ab[a][c] = 'S';
    if (cb[a][c] != 'A' && cb[a][c] != 'B')
      break;
  }
}

void H(int a, int b) {
  if (cb[a][b + 1] == 'A' && b + 2 <= 9 && a - 1 >= 1)
    ab[a - 1][b + 2] = 'S';
  if (cb[a][b + 1] == 'A' && b + 2 <= 9 && a + 1 < 11)
    ab[a + 1][b + 2] = 'S';
  if (cb[a][b - 1] == 'A' && b - 2 >= 1 && a - 1 >= 1)
    ab[a - 1][b - 2] = 'S';
  if (cb[a][b - 1] == 'A' && b - 2 >= 1 && a + 1 < 11)
    ab[a + 1][b - 2] = 'S';
  if (cb[a + 1][b] == 'A' && b - 1 >= 1 && a + 2 < 11)
    ab[a + 2][b - 1] = 'S';
  if (cb[a + 1][b] == 'A' && b + 1 <= 9 && a + 2 < 11)
    ab[a + 2][b + 1] = 'S';
  if (cb[a - 1][b] == 'A' && b - 1 >= 1 && a - 2 >= 1)
    ab[a - 2][b - 1] = 'S';
  if (cb[a - 1][b] == 'A' && b + 1 <= 9 && a - 2 >= 1)
    ab[a - 2][b + 1] = 'S';
}

void C(int a, int b) {
  if (b >= 4 && b <= 6 && a == 1)
    if (cb[2][b] != 'A' && cb[2][b] != 'B')
      ab[3][b] = 'S';
  int c, d;
  for (c = a - 1; c >= 1; c--) {
    if (cb[c][b] == 'B')
      return;
    if (cb[c][b] != 'A')
      break;
  }
  for (d = c - 1; d >= 1; d--) {
    ab[d][b] = 'S';
    if (cb[d][b] != 'A' && cb[d][b] != 'B')
      break;
  }
  for (c = b + 1; c <= 9; c++) {
    if (cb[a][c] == 'B')
      return;
    if (cb[a][c] != 'A')
      break;
  }
  for (d = c + 1; d <= 9; d++) {
    ab[a][d] = 'S';
    if (cb[a][d] != 'A' && cb[a][d] != 'B')
      break;
  }
  for (c = b - 1; c >= 1; c--) {
    if (cb[a][c] == 'B')
      return;
    if (cb[a][c] != 'A')
      break;
  }
  for (d = c - 1; d >= 1; d--) {
    ab[a][d] = 'S';
    if (cb[a][d] != 'A' && cb[a][d] != 'B')
      break;
  }
}

int judge(int i, int j) {
  int ok = 1;
  if (i + 1 < 4 && ab[i + 1][j] != 'S')
    ok = 0;
  if (i - 1 > 0 && ab[i - 1][j] != 'S')
    ok = 0;
  if (j + 1 < 7 && ab[i][j + 1] != 'S')
    ok = 0;
  if (j - 1 > 3 && ab[i][j - 1] != 'S')
    ok = 0;
  return ok;
}

int main(void) {
  int n, i, j, Ch[8][3], a1, b1;
  while (cin >> n >> a1 >> b1 && n && a1 && b1) {
    memset(cb, 'A', sizeof(cb));
    memset(ab, 'A', sizeof(ab));
    memset(Ch, 0, sizeof(Ch));
    cb[a1][b1] = 'B';
    char ch;
    for (int k = 0; k < n; k++) {
      cin >> ch >> i >> j;
      cb[i][j] = ch;
      Ch[k][0] = i;
      Ch[k][1] = j;
    }
    for (int m = 0; m < n; m++) {
      int a = Ch[m][0], b = Ch[m][1];
      if (cb[a][b] == 'R' || cb[a][b] == 'G')
        RG(a, b);
      else if (cb[a][b] == 'H')
        H(a, b);
      else if (cb[a][b] == 'C')
        C(a, b);
    }
    puts(judge(a1, b1) ? "YES" : "NO");
  }
  return 0;
}
