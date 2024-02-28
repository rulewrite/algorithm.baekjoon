#include <iostream>

int factorial(int num) {
  if (num <= 1) {
    return 1;
  }

  return factorial(num - 1) * num;
}

int main(void) {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);
  printf("%d", factorial(n));

  return 0;
}