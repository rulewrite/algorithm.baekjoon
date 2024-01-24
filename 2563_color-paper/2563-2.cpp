#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int paperCount;
  scanf("%d", &paperCount);

  int const MATRIX_SIZE = 100;
  bool matrix[MATRIX_SIZE][MATRIX_SIZE] = { false };

  int const PAPER_SIZE = 10;

  for (int i = 0; i < paperCount; ++i) {
    int leftX;
    int bottomY;
    scanf("%d %d", &leftX, &bottomY);

    int rightX = leftX + PAPER_SIZE;
    int topY = bottomY + PAPER_SIZE;

    for (int x = leftX; x < rightX; ++x) {
      for (int y = bottomY; y < topY; ++y) {
        matrix[x][y] = true;
      }
    }
  }

  // for (int i = 0; i < MATRIX_SIZE; ++i) {
  //   for (int j = 0; j < MATRIX_SIZE; ++j) {
  //     printf("%d", matrix[i][j]);
  //   }
  //   printf("\n");
  // }

  int coloredCount = 0;
  for (int i = 0; i < MATRIX_SIZE; ++i) {
    for (int j = 0; j < MATRIX_SIZE; ++j) {
      coloredCount += matrix[i][j];
    }
  }
  printf("%d", coloredCount);

  return 0;
}
