#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int d, s, b, n;
const int maxn = 6500;
char a[7][maxn];
bool parity; // 1 odd; 0 even

bool read() {
  cin >> d;
  if (!d)
    return false;
  cin >> s >> b;
  getchar(); //加上这句话十分关键，否则就WA了！！！因为会把换行符作为 ch
  memset(a, 0, sizeof(a));
  char ch = getchar();
  parity = ch == 'O';
  if (ch == '\n')
    cout << "Wrong Answer because of this fault!!!" << endl;
  getchar();
  n = s * b;
  for (int i = 0; i < d; i++)
    cin >> a[i];
  return true;
}

bool solve() {
  int i, j;
  //对每列做检查，看是否需要恢复数据，以及检查是否满足所给校验规律
  for (i = 0; i < n; i++) {
    bool flag = false;
    // 用来标记是否出现两次x，若是则退出，无法恢复
    int broke = -1;
    for (j = 0; j < d; j++) {
      // 用引用，则数据的使用和修改都非常方便
      char &ch = a[j][i];
      if (ch == '1')
        flag = !flag;
      if (ch == 'x') {
        if (broke == -1)
          broke = j;
        else
          return false;
      }
    }
    if (broke == -1 && flag != parity)
      return false; //磁盘没有损坏，不需恢复，但校验不合法
    if (broke != -1)
      a[broke][i] = (parity == flag) ? '0' : '1'; // 恢复
  }
  return true;
}

void print(bool ch) {
  if (!ch) {
    cout << "invalid." << endl;
    return;
  } else
    cout << "valid, contents are: ";

  int cnt = 0, sum = 0;

  for (int i = 0; i < b; i++) //枚举硬盘被分为的b个部分
  {
    int pos = i * s;
    for (int j = 0; j < d; j++) {
      if (i % d == j)
        continue; //若为校验位，应该跳过
      for (int k = 0; k < s; k++) {
        sum <<= 1;
        sum += a[j][pos + k] == '1';
        cnt++;
        if (cnt == 4) {
          printf("%X", sum);
          sum = 0;
          cnt = 0;
        }
      }
    }
  }
  // 若最后一个数不满4位，不能直接构成16进制，则末尾补0
  if (cnt)
    printf("%X", sum << (4 - cnt));
  cout << endl;
}

int main() {
  int kase = 0;
  while (read()) {
    cout << "Disk set " << ++kase << " is ";
    print(solve());
  }
  return 0;
}