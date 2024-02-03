#include <stdio.h>
#include <stack>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int caseCount;
  scanf("%d", &caseCount);

  for (; caseCount; --caseCount) {
    int a;
    int b;
    scanf("%d %d", &a, &b);

    int sum = a + b;
    // printf("----%d\n", sum);

    stack<int> binary;
    int upNum = 0;
    while (sum) {
      int num = (sum % 10) + upNum;
      // printf("   %d + %d = %d -> %d\n", (sum % 10), upNum, num, num % 2);

      upNum = num / 2;
      binary.push(num % 2);

      sum /= 10;
    }

    while (upNum) {
      binary.push(upNum % 2);
      upNum /= 2;
    }

    while (!binary.empty()) {
      printf("%d", binary.top());
      binary.pop();
    }
    printf("\n");
  }

  return 0;
}