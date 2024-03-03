#include <iostream>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int coinTypeCount = 0;
  int goal = 0;
  scanf("%d %d", &coinTypeCount, &goal);

  int coinTypes[coinTypeCount];

  for (int i = 0; i < coinTypeCount; ++i) {
    scanf("%d", &coinTypes[i]);
  }

  int coinCount = 0;
  for (int i = coinTypeCount - 1; i >= 0; --i) {
    // printf("%d: %d\n", i, coinTypes[i]);
    int coinType = coinTypes[i];

    if (coinType > goal) {
      continue;
    }

    // printf("  %d %d\n", coinCount, goal);
    coinCount += goal / coinType;
    goal = goal % coinType;
    // printf("  %d %d\n", coinCount, goal);

    if (goal <= 0) {
      break;
    }
  }

  printf("%d", coinCount);

  return 0;
}