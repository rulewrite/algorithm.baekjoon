#include <iostream>

int main(void) {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);

  if (n == 0) {
    printf("0");

    return 0;
  }

  int prev = 0;
  int tempPrev = 0;
  int current = 1;
  for (int i = 1; i < n; ++i) {
    tempPrev = prev;
    prev = current;
    current = tempPrev + current;
  }

  printf("%d", current);

  return 0;
}