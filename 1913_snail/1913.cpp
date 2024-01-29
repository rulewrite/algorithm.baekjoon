#include <stdio.h>

int main(void) {
  // freopen("example.txt", "r", stdin);
  int n, goal;
  scanf("%d %d", &n, &goal);

  int snail[n][n];
  // for (int x = 0; x < n; ++x) {
  //   for (int y = 0; y < n; ++y) {
  //     snail[x][y] = 0;
  //   }
  // }

  int const END_NUM = n * n;
  int const STEP_COUNT = END_NUM - 1;
  int steps[STEP_COUNT][2];
  // for (int i = 0; i < STEP_COUNT; ++i) {
  //   steps[i][0] = 0;
  //   steps[i][1] = 0;
  // }

  int up[2] = { 0, -1 };
  int right[2] = { 1, 0 };
  int down[2] = { 0, 1 };
  int left[2] = { -1, 0 };

  int wallCount = 0;
  for (int i = 1; wallCount < STEP_COUNT; ++i) {
    int prevWallCount = wallCount;
    wallCount += (8 * i);
    int const STEP = (2 * i);
    // printf("==start: %d, end: %d, step: %d\n", prevWallCount, wallCount, STEP);
    int rightIndex = prevWallCount + (STEP * 1);
    int downIndex = prevWallCount + (STEP * 2);
    int leftIndex = prevWallCount + (STEP * 3);
    // printf("==right: %d, down: %d, left: %d\n", rightIndex, downIndex, leftIndex);

    for (int wallIndex = prevWallCount; wallIndex < wallCount; ++wallIndex) {
      // printf("  %d  ", wallIndex);

      if (wallIndex == prevWallCount) {
        steps[wallIndex][0] = up[0];
        steps[wallIndex][1] = up[1];
        // printf("up\n");
        continue;
      }

      bool isRight = wallIndex < rightIndex;
      if (isRight) {
        steps[wallIndex][0] = right[0];
        steps[wallIndex][1] = right[1];
        // printf("right\n");
        continue;
      }

      bool isDown = wallIndex < downIndex;
      if (isDown) {
        steps[wallIndex][0] = down[0];
        steps[wallIndex][1] = down[1];
        // printf("down\n");
        continue;
      }

      bool isLeft = wallIndex < leftIndex;
      if (isLeft) {
        steps[wallIndex][0] = left[0];
        steps[wallIndex][1] = left[1];
        // printf("left\n");
        continue;
      }

      // printf("up\n");
      steps[wallIndex][0] = up[0];
      steps[wallIndex][1] = up[1];
    }
  }


  int x = (n - 1) / 2;
  int y = (n - 1) / 2;
  int value = 1;
  snail[y][x] = value;
  for (int stepIndex = 0; stepIndex < STEP_COUNT; ++stepIndex) {
    // printf("before: %d %d, step: %d %d, ", x, y, steps[stepIndex][0], steps[stepIndex][1]);
    x += steps[stepIndex][0];
    y += steps[stepIndex][1];
    snail[y][x] = ++value;
    // printf("after: %d %d\n", x, y);
  }
  // printf("------\n");

  int goalPosition[2];
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      int value = snail[x][y];
      printf("%d ", value);

      if (value == goal) {
        goalPosition[0] = x;
        goalPosition[1] = y;
      }
    }
    printf("\n");
  }

  printf("%d %d", (goalPosition[0] + 1), (goalPosition[1] + 1));

  return 0;
}