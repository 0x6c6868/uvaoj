#include <stdio.h>

char s[13];

int check(int i, int j) { return 1; }

int main(void) {
  while (scanf("%s", s) == 1) {

    int ok = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 4; j++) {
        if (check(i, j))
          ok = 1;
      }
    }
    printf("%s\n", ok ? "TRUE" : "FALSE");
  }
  return 0;
}