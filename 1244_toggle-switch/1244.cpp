#include <stdio.h>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int switchCount = 0; // <= 100
  scanf("%d", &switchCount);

  bool switches[switchCount];
  for (int i = 0;i < switchCount; ++i) {
    // 바로 받을 수 있는 방법 없나? scanf("%d", &switches[i]);
    int n = 0;
    scanf("%d", &n);
    switches[i] = n;
  }

  int studentCount = 0; // <= 100
  scanf("%d", &studentCount);

  for (int i = 0;i < studentCount; ++i) {
    int gender = 0;
    int num = 0;
    scanf("%d %d", &gender, &num);

    bool isMale = gender == 1;
    if (isMale) {
      for (int j = 0;j < switchCount; ++j) {
        if ((j + 1) % num) {
          continue;
        }

        switches[j] = !switches[j];
      }

      continue;
    }

    int index = num - 1;
    int switchLastIndex = switchCount - 1;
    if (index == 0 || index == switchLastIndex) {
      switches[index] = !switches[index];

      continue;
    }

    int stepCount = 0;
    while (true) {
      // 카운트 올려도 되는지 검증
      int nextStepCount = stepCount + 1;
      int startIndex = index - nextStepCount;
      int lastIndex = index + nextStepCount;

      if (startIndex < 0 || lastIndex > switchLastIndex) {
        break;
      }

      if (switches[startIndex] != switches[lastIndex]) {
        break;
      }

      stepCount = nextStepCount;
    }

    // printf("%d, %d %d\n", index, index - stepCount, index + stepCount);
    for (int j = index - stepCount; j <= index + stepCount; ++j) {
      switches[j] = !switches[j];
    }
  }

  for (int i = 0;i < switchCount; ++i) {
    printf("%d ", switches[i]);
    if ((i + 1) % 20 == 0) {
      printf("\n");
    }
  }

  return 0;
}