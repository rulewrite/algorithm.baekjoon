#include <stdio.h>

int main(void) {
  // freopen("example.txt", "r", stdin);

  int const RECTANGLE_COUNT = 4;
  int const SIZE = 100;
  int area[SIZE][SIZE] = { 0 };

  for (int i = 0; i < RECTANGLE_COUNT; ++i) {
    int leftX, bottomY, rightX, topY;

    scanf("%d %d %d %d", &leftX, &bottomY, &rightX, &topY);

    for (int x = leftX; x < rightX; ++x) {
      for (int y = bottomY; y < topY; ++y) {
        area[x][y] = 1;
      }
    }
  }

  int sum = 0;
  for (int x = 0; x < SIZE; ++x) {
    for (int y = 0; y < SIZE; ++y) {
      sum += area[x][y];
    }
  }

  printf("%d", sum);

  return 0;
}