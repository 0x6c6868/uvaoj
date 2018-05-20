#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _face {
  int x;
  int y;
} Face;

Face faces[6];

int cmp(const void *a, const void *b) {
  int flag = ((Face *)a)->x - ((Face *)b)->x;
  if (flag != 0) {
    return flag;
  }
  return ((Face *)a)->y - ((Face *)b)->y;
}

int check() {
  if (memcmp(faces, faces + 1, sizeof(Face)) ||
      memcmp(faces + 2, faces + 3, sizeof(Face)) ||
      memcmp(faces + 4, faces + 5, sizeof(Face)))
    return 0;
  if (faces[0].x != faces[2].x || faces[0].y != faces[4].x ||
      faces[2].y != faces[4].y)
    return 0;
  return 1;
}

int main(void) {
  while (scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &faces[0].x, &faces[0].y,
               &faces[1].x, &faces[1].y, &faces[2].x, &faces[2].y, &faces[3].x,
               &faces[3].y, &faces[4].x, &faces[4].y, &faces[5].x,
               &faces[5].y) == 12) {
    for (int i = 0; i < 6; i++) {
      if (faces[i].x > faces[i].y) {
        int t = faces[i].x;
        faces[i].x = faces[i].y;
        faces[i].y = t;
      }
    }
    qsort(faces, 6, sizeof(Face), cmp);
    printf("%s\n", check() ? "POSSIBLE" : "IMPOSSIBLE");
  }
  return 0;
}
