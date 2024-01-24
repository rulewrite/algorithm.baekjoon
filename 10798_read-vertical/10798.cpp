#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int const ROWS_LENGTH = 5;
  int const LENGTH = 15;
  char rows[ROWS_LENGTH][LENGTH];

  for (int i = 0; i < ROWS_LENGTH; i++) {
    for (int j = 0; j < LENGTH; j++) {
      rows[i][j] = '\0';
    }
  }

  for (int rowIndex = 0; rowIndex < ROWS_LENGTH; ++rowIndex) {
    scanf("%s", rows[rowIndex]);
  }

  for (int charIndex = 0; charIndex < LENGTH; ++charIndex) {
    for (int rowIndex = 0; rowIndex < ROWS_LENGTH; ++rowIndex) {
      char c = rows[rowIndex][charIndex];
      int asciiCode = c;

      if ((48 <= asciiCode && asciiCode <= 57) ||
        (65 <= asciiCode && asciiCode <= 90) ||
        (97 <= asciiCode && asciiCode <= 122)) {
        printf("%c", c);
      }
    }
  }

  return 0;
}