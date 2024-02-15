#include <iostream>

int main(void) {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);

  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  printf("%d", result);

  return 0;
}