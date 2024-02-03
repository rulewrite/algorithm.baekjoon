#include <stdio.h>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int charge[4] = { 0 };
  scanf("%d %d %d", &charge[1], &charge[2], &charge[3]);

  int const TRUCK_COUNT = 3;
  int const TIME_COUNT = 100;
  int timeTable[TIME_COUNT] = { 0 };
  for (int i = 0; i < TRUCK_COUNT; ++i) {
    int inTime = 0;
    int outTime = 0;
    scanf("%d %d", &inTime, &outTime);

    for (int j = inTime; j < outTime; ++j) {
      ++timeTable[j];
    }
  }

  int totalCharge = 0;
  for (int i = 0; i < TIME_COUNT; ++i) {
    int parkingCount = timeTable[i];

    totalCharge += (charge[parkingCount] * parkingCount);
  }
  printf("%d", totalCharge);

  return 0;
}