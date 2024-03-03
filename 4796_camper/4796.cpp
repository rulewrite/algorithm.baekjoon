#include <iostream>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int caseCount = 0;
  while (true) {
    ++caseCount;

    // 1 20 39, 5 8 20
    int availableDays;
    int totalDays;
    int vacationDays;

    scanf("%d %d %d", &availableDays, &totalDays, &vacationDays);

    if (!availableDays && !totalDays && !vacationDays) {
      break;
    }

    int days = (vacationDays / totalDays) * availableDays;

    // 19 = 39 % 20, 4 = 20 % 8
    int remainDays = vacationDays % totalDays;
    // 19 > 1, 4 > 5
    if (remainDays > availableDays) {
      remainDays = availableDays;
    }

    days += remainDays;

    printf("Case %d: %d\n", caseCount, days);
  }

  return 0;
}