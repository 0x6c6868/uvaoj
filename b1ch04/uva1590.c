#include <stdio.h>

unsigned int tmp[1000] = {0};

void print_addr(unsigned int foo) {
  printf("%u.%u.%u.%u\n", (foo & 0xff000000) >> 24, (foo & 0xff0000) >> 16,
         (foo & 0xff00) >> 8, foo & 0xff);
}

void debug_print(int n) {
  for (int i = 0; i < n; i++)
    print_addr(tmp[i]);
}

void count_subnet_mask(int n) {

  unsigned int foo = 0xffffffff;

  int rst = -1;
  for (int i = 31; i >= 0; i--) {

    unsigned int flag = tmp[0] & (1 << i);
    for (int j = 1; j < n; j++) {
      if (flag != (tmp[j] & (1 << i))) {
        rst = i;
        goto done;
      }
    }
  }
done:

  for (int i = 0; i <= rst; i++) {
    foo -= (1 << i);
  }

  print_addr(tmp[0] & foo);
  print_addr(foo);
}

int main(void) {
  int n;
  while (scanf("%d", &n) == 1 && n) {
    for (int i = 0; i < n; i++) {
      unsigned int t1, t2, t3, t4;
      scanf("%u.%u.%u.%u", &t1, &t2, &t3, &t4);
      tmp[i] = (t1 << 24) + (t2 << 16) + (t3 << 8) + t4;
    }
    count_subnet_mask(n);
  }
  return 0;
}
