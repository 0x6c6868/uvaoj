/*
 ***********
 *         *
 * 对拍程序 *
 *         *
 ***********
 */

// import random

// for _ in range(10000):

//     n = random.randint(2, 9)
//     count = random.randint(1, n * (n-1) * 2)

//     print(n)
//     print(count)

//     h_set = [ (i, j) for i in range(1, n+1) for j in range(1, n) ]
//     v_set = [ (i, j) for i in range(1, n) for j in range(1, n+1) ]

//     while count > 0:

//         if h_set and v_set:
//             _type = random.choice(["H", "V"])
//         elif h_set:
//             _type = "H"
//         elif v_set:
//              _type = "V"

//         if _type == "H":
//             x, y = random.choice(h_set)
//             h_set.remove((x, y))
//         elif _type == "V":
//             x, y = random.choice(v_set)
//             v_set.remove((x, y))

//         if _type == "V":
//             print(_type, x, y)
//         else:
//             print(_type, y, x)

//         count -= 1

/*
 ***********
 *         *
 * AC的代码 *
 *         *
 ***********
 */

// #include <algorithm>
// #include <iostream>
// #include <cstdlib>
// #include <cstring>
// #include <cstdio>
// #include <cmath>

// using namespace std;

// int H[10][10];
// int V[10][10];

// int main()
// {
//     int  n,m,x,y,T = 0;
//     char c;
//     while (~scanf("%d%d",&n,&m)) {
//         getchar();
//         for (int i = 1 ; i <= n ; ++ i)
//         for (int j = 1 ; j <= n ; ++ j)
//             V[i][j] = H[i][j] = 0;
//         for (int i = 1 ; i <= m ; ++ i) {
//             scanf("%c%d%d",&c,&x,&y);
//             getchar();
//             if (c == 'H')
//                 H[x][y] = 1;
//             else
//                 V[y][x] = 1;
//         }
//         if (T ++) printf("\n**********************************\n\n");
//         printf("Problem #%d\n\n",T);

//         int sum = 0;
//         for (int l = 1 ; l <= n ; ++ l) {
//             int count = 0,flag = 0;
//             for (int i = 1 ; i+l <= n ; ++ i)
//             for (int j = 1 ; j+l <= n ; ++ j) {
//                 flag = 1;
//                 for (int h = j ; h < j+l ; ++ h)
//                     if (!H[i][h] || !H[i+l][h]) flag = 0;
//                 for (int v = i ; v < i+l ; ++ v)
//                     if (!V[v][j] || !V[v][j+l]) flag = 0;
//                 count += flag;
//             }
//             sum += count;
//             if (count) printf("%d square (s) of size %d\n",count,l);
//         }

//         if (!sum) printf("No completed squares can be found.\n");
//     }
//     return 0;
// }

#include <stdio.h>
#include <string.h>

#define MAXN 10

int flag = 0;
int h_space[MAXN][MAXN];
int v_space[MAXN][MAXN];

int is_square(int i, int j, int t) {
  for (int x = 0; x < t; x++) {
    if (h_space[i][j + x] == 0 || h_space[i + t][j + x] == 0) {
      return 0;
    }
    if (v_space[i + x][j] == 0 || v_space[i + x][j + t] == 0) {
      return 0;
    }
  }
  return 1;
}

int count(int n, int t) {
  int count = 0;
  for (int i = 1; i + t <= n; i++) {
    for (int j = 1; j + t <= n; j++) {
      count += is_square(i, j, t);
    }
  }
  return count;
}

void Do(int n) {
  for (int i = 1; i <= n; i++) {
    int tmp = 0;
    if ((tmp = count(n, i)) > 0) {
      flag = 1;
      printf("%d square (s) of size %d\n", tmp, i);
    }
  }
}

int main(void) {

  int kase = 0;

  int n, count;
  while (scanf("%d%d", &n, &count) == 2) {

    flag = 0;
    memset(h_space, 0, sizeof(h_space));
    memset(v_space, 0, sizeof(v_space));

    char t;
    int t1, t2;
    for (int i = 0; i < count; i++) {
      getchar(); // 过滤换行
      scanf("%c %d %d", &t, &t1, &t2);
      if (t == 'H') {
        h_space[t1][t2] = 1;
      } else if (t == 'V') {
        v_space[t2][t1] = 1;
      }
    }

    if (kase != 0)
      printf("\n**********************************\n\n");

    printf("Problem #%d\n\n", ++kase);

    Do(n);

    if (!flag)
      printf("No completed squares can be found.\n");
  }

  return 1;
}
