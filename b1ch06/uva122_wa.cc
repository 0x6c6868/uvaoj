#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 10000

#define bool int
#define true 1
#define false 0

typedef struct _node {
  bool have_value;
  int v;
  struct _node *left, *right;
} Node;
Node *root;

// 输入数据是否有误
bool failed;

Node *newnode() {
  Node *t = (Node *)malloc(sizeof(Node));
  t->have_value = false;
  t->left = NULL;
  t->right = NULL;
  return t;
}

void addnode(int v, char *s) {
  int n = strlen(s);
  Node *u = root;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'L') {
      if (u->left == NULL)
        u->left = newnode();
      u = u->left;
    } else if (s[i] == 'R') {
      if (u->right == NULL)
        u->right = newnode();
      u = u->right;
    }
  }
  if (u->have_value)
    failed = true;
  u->v = v;
  u->have_value = true;
}

Node *queue[maxn];
int q_head;
int q_tail;

void queue_init() {
  q_head = 0;
  q_tail = 0;
}

bool queue_empty() { return q_head >= q_tail; }

Node *queue_front() { return queue[q_head]; }

void queue_pop() { q_head++; }

void queue_push(Node *n) {
  queue[q_tail] = n;
  q_tail++;
}

int rst[maxn];
int rst_len = 0;
bool bfs() {
  rst_len = 0;
  queue_init();
  queue_push(root);
  while (!queue_empty()) {
    Node *u = queue_front();
    queue_pop();
    if (!u->have_value)
      return false;
    rst[rst_len++] = u->v;
    if (u->left != NULL)
      queue_push(u->left);
    if (u->right != NULL)
      queue_push(u->right);
  }
  return true;
}

bool read_input() {
  failed = false;
  root = newnode();
  for (;;) {
    char s[maxn];
    if (scanf("%s", s) != 1)
      return false;
    if (!strcmp(s, "()"))
      break;
    int v;
    sscanf(&s[1], "%d", &v);
    addnode(v, strchr(s, ',') + 1);
  }
  return true;
}

int main(void) {
  while (read_input()) {
    if (failed) {
      printf("not complete\n");
      continue;
    }
    if (!bfs())
      printf("not complete\n");
    if (rst_len > 1) {
      for (int i = 0; i < rst_len - 1; i++)
        printf("%d ", rst[i]);
      printf("%d", rst[rst_len - 1]);
      putchar('\n');
    }
  }
  return 0;
}
