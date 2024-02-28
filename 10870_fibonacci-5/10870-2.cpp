#include <iostream>

int dp[20] = { 0 };

int fibonacci(int num) {
  if (num == 0) {
    return 0;
  }

  if (num == 1) {
    return 1;
  }

  if (dp[num] == 0) {
    dp[num] = fibonacci(num - 1) + fibonacci(num - 2);
  }

  return dp[num];
}

int main(void) {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);
  printf("%d", fibonacci(n));

  return 0;
}