#include <iostream>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int meetingCount = 0;
  scanf("%d", &meetingCount);

  int meetings[meetingCount][2];
  for (int i = 0; i < meetingCount; ++i) {
    scanf("%d %d", &meetings[i][0], &meetings[i][1]);
  }

  // 버블정렬
  int lastIndex = meetingCount - 1;
  for (int i = lastIndex; i > 0; --i) {
    bool isSwapped = false;

    for (int j = 0; j < i; ++j) {
      int current = meetings[j][1];
      int next = meetings[j + 1][1];

      if (current > next) {
        isSwapped = true;
        int temp[2] = { meetings[j][0],meetings[j][1] };
        meetings[j][0] = meetings[j + 1][0];
        meetings[j][1] = meetings[j + 1][1];
        meetings[j + 1][0] = temp[0];
        meetings[j + 1][1] = temp[1];
      }
    }

    if (!isSwapped) {
      break;
    }
  }

  int count = 0;
  int lastTime = 0;
  for (int i = 0; i < meetingCount; ++i) {
    int start = meetings[i][0];
    int end = meetings[i][1];

    if (start >= lastTime) {
      // printf("%d %d\n", start, end);
      lastTime = end;
      ++count;
    }
  }

  printf("%d", count);

  return 0;
}