#include <iostream>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int holeCount = 0;
  int tapeSize = 0;
  scanf("%d %d", &holeCount, &tapeSize);

  int holePositions[holeCount];
  for (int i = 0; i < holeCount; ++i) {
    scanf("%d", &holePositions[i]);
  }

  // 버블정렬
  int holeLastIndex = holeCount - 1;
  for (int i = holeLastIndex; i > 0; --i) {
    bool isSwapped = false;

    for (int j = 0; j < i; ++j) {
      int current = holePositions[j];
      int next = holePositions[j + 1];

      if (current > next) {
        isSwapped = true;
        holePositions[j] = next;
        holePositions[j + 1] = current;
      }
    }

    if (!isSwapped) {
      break;
    }
  }

  int tapeCount = 0;
  int tepeEnd = 0;
  for (int i = 0; i < holeCount; ++i) {
    // printf("%d\n", holePositions[i]);
    int holePosition = holePositions[i];

    if (holePosition <= tepeEnd) {
      continue;
    }

    ++tapeCount;
    tepeEnd = holePosition + (tapeSize - 1);
  }

  printf("%d", tapeCount);

  return 0;
}