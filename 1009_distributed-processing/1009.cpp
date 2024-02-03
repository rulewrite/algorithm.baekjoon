#include <stdio.h>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int caseCount = 0;
  scanf("%d", &caseCount);

  for (int i = 0; i < caseCount; ++i) {
    int base = 0;
    int exponent = 0;
    scanf("%d %d", &base, &exponent);

    int result = 1;
    for (int j = 0; j < exponent; ++j) {
      result = (result * base) % 10;
    }
    printf("%d\n", result == 0 ? 10 : result);
  }

  return 0;
}