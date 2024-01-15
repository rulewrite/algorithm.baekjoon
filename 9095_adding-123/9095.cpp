#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int dp[11] = { 1,2,4 };

  for (int i = 3; i < 11; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
  }

  int count;
  scanf("%d", &count);

  int number;
  for (int i = 0; i < count; ++i) {
    scanf("%d", &number);
    printf("%d\n", dp[number - 1]);
  }

  return 0;
}