#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int rowLength;
  int colLength;
  scanf("%d %d", &rowLength, &colLength);


  const int MATRIX_LENGTH = 2;
  int matrixs[MATRIX_LENGTH][rowLength][colLength];

  for (int i = 0; i < MATRIX_LENGTH; ++i) {
    for (int rowIndex = 0; rowIndex < rowLength; ++rowIndex) {
      for (int colIndex = 0; colIndex < colLength; ++colIndex) {
        scanf("%d", &matrixs[i][rowIndex][colIndex]);
      }
    }
  }

  for (int rowIndex = 0; rowIndex < rowLength; ++rowIndex) {
    for (int colIndex = 0; colIndex < colLength; ++colIndex) {
      printf("%d", matrixs[0][rowIndex][colIndex] + matrixs[1][rowIndex][colIndex]);

      bool isLast = colIndex == colLength - 1;
      if (isLast) {
        continue;
      }
      printf(" ");
    }

    printf("\n");
  }

  return 0;
}