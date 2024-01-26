#include <stdio.h>

int main(void) {
  // freopen("example.txt", "r", stdin);

  int const RECTANGLE_COUNT = 4;
  int rectangles[RECTANGLE_COUNT][4];

  for (int i = 0; i < RECTANGLE_COUNT; ++i) {
    scanf("%d %d %d %d", &rectangles[i][0], &rectangles[i][1], &rectangles[i][2], &rectangles[i][3]);
    // printf("%d %d %d %d\n", rectangles[i][0], rectangles[i][1], rectangles[i][2], rectangles[i][3]);
  }

  int const SIZE = 100;
  int area[SIZE][SIZE] = { 0 };
  for (int i = 0; i < RECTANGLE_COUNT; ++i) {
    int leftX = rectangles[i][0];
    int bottomY = rectangles[i][1];
    int rightX = rectangles[i][2];
    int topY = rectangles[i][3];

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