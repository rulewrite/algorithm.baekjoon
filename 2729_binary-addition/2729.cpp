#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int caseCount;
  scanf("%d", &caseCount);

  for (; caseCount; --caseCount) {
    string a;
    string b;

    cin >> a;
    cin >> b;

    // printf("----%s %s\n", a.c_str(), b.c_str());

    int aIndex = a.length() - 1;
    int bIndex = b.length() - 1;

    stack<int> binary;
    int carry = 0;
    while (aIndex >= 0 || bIndex >= 0 || carry) {
      int sum = carry;

      if (aIndex >= 0) {
        sum += a[aIndex] - '0';
        --aIndex;
      }

      if (bIndex >= 0) {
        sum += b[bIndex] - '0';
        --bIndex;
      }

      carry = sum / 2;
      binary.push(sum % 2);
    }

    while (!binary.empty()) {
      printf("%d", binary.top());
      binary.pop();
    }

    printf("\n");
  }

  return 0;
}