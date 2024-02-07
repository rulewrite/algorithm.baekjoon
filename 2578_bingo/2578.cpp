#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int const BINGO_SIZE = 5;
int bingoBoard[BINGO_SIZE][BINGO_SIZE] = { 0 };
int rowCounts[BINGO_SIZE] = { 0 };
int colCounts[BINGO_SIZE] = { 0 };
int diagonalCounts[2] = { 0 };
int diagonalIndicies[2][BINGO_SIZE][2] = { 0 };

void setDiagonalIndicies() {
  for (int i = 0; i < BINGO_SIZE; ++i) {
    diagonalIndicies[0][i][0] = i;
    diagonalIndicies[0][i][1] = i;
  }

  int const BINGO_LAST_INDEX = BINGO_SIZE - 1;
  for (int i = BINGO_LAST_INDEX; i >= 0; --i) {
    diagonalIndicies[1][i][0] = i;
    diagonalIndicies[1][i][1] = BINGO_LAST_INDEX - i;
  }

  // for (int i = 0; i < BINGO_SIZE; ++i) {
  //   printf("%d %d\n", diagonalIndicies[0][i][0], diagonalIndicies[0][i][1]);
  // }
  // printf("------\n");
  // for (int i = 0; i < BINGO_SIZE; ++i) {
  //   printf("%d %d\n", diagonalIndicies[1][i][0], diagonalIndicies[1][i][1]);
  // }
  // printf("------\n");
}

int sign(int n) {
  bool isFound = false;
  int bingoCount = 0;

  for (int rowIndex = 0; rowIndex < BINGO_SIZE; ++rowIndex) {
    for (int colIndex = 0; colIndex < BINGO_SIZE; ++colIndex) {
      if (bingoBoard[rowIndex][colIndex] != n) {
        continue;
      }

      ++rowCounts[rowIndex];
      ++colCounts[colIndex];
      bingoCount += (rowCounts[rowIndex] >= BINGO_SIZE) + (colCounts[colIndex] >= BINGO_SIZE);


      if (diagonalCounts[0] < BINGO_SIZE) {
        for (int i = 0; i < BINGO_SIZE; ++i) {
          if (diagonalIndicies[0][i][0] == rowIndex && diagonalIndicies[0][i][1] == colIndex) {
            ++diagonalCounts[0];
            break;
          }
        }
        bingoCount += (diagonalCounts[0] >= BINGO_SIZE);
      }

      if (diagonalCounts[1] < BINGO_SIZE) {
        for (int i = 0; i < BINGO_SIZE; ++i) {
          if (diagonalIndicies[1][i][0] == rowIndex && diagonalIndicies[1][i][1] == colIndex) {
            ++diagonalCounts[1];
            break;
          }
        }
        bingoCount += (diagonalCounts[1] >= BINGO_SIZE);
      }

      // printf("%d LT-RB: %d, LB-RT: %d\n", n, diagonalCounts[0], diagonalCounts[1]);

      isFound = true;
      break;
    }

    if (isFound) {
      break;
    }
  }



  return bingoCount;
}

int main(void) {
  // freopen("example.txt", "r", stdin);

  setDiagonalIndicies();
  for (int rowIndex = 0; rowIndex < BINGO_SIZE; ++rowIndex) {
    scanf("%d %d %d %d %d", &bingoBoard[rowIndex][0], &bingoBoard[rowIndex][1], &bingoBoard[rowIndex][2], &bingoBoard[rowIndex][3], &bingoBoard[rowIndex][4]);

    // printf("%d %d %d %d %d\n", bingoBoard[rowIndex][0], bingoBoard[rowIndex][1], bingoBoard[rowIndex][2], bingoBoard[rowIndex][3], bingoBoard[rowIndex][4]);
  }

  int bingoCount = 0;
  int const LAST_INDEX = BINGO_SIZE * BINGO_SIZE;
  for (int i = 0; i < LAST_INDEX; ++i) {
    int n = 0;
    scanf("%d", &n);

    bingoCount += sign(n);
    // printf("bingoCount %d, n: %d\n", bingoCount, n); // 13 > 3 > 25

    if (bingoCount >= 3) {
      printf("%d", i + 1);

      break;
    }
  }

  return 0;
}