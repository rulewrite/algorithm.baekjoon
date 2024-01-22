#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int const LENGTH = 9;
  int max = 0;
  int position[2];

  for (int rowIndex = 0; rowIndex < LENGTH; ++rowIndex) {
    for (int colIndex = 0; colIndex < LENGTH; ++colIndex) {
      int current;
      scanf("%d", &current);

      if (max >= current) {
        continue;
      }

      max = current;
      position[0] = rowIndex;
      position[1] = colIndex;
    }
  }

  printf("%d\n", max);
  printf("%d %d", position[0] + 1, position[1] + 1);

  return 0;
}