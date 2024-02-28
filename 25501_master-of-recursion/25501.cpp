#include <stdio.h>
#include <string.h>

using namespace std;

int recursionCount = 0;
int recursion(const char* text, int leftIndex, int rightIndex) {
  ++recursionCount;
  // printf("%d, %d\n", leftIndex, rightIndex);
  // 두 글자가 다르다면
  if (text[leftIndex] != text[rightIndex]) {
    return 0;
  }

  // 양 끝이 겹쳤다면
  if (leftIndex >= rightIndex) {
    return 1;
  }

  // 다음 글자 확인
  return recursion(text, leftIndex + 1, rightIndex - 1);
}

int isPalindrome(const char* text) {
  recursionCount = 0;

  int const LAST_INDEX = strlen(text) - 1;
  // printf("%s: %d\n", text, LAST_INDEX);

  return recursion(text, 0, LAST_INDEX);
}

int main() {
  // printf("ABBA: %d\n", isPalindrome("ABBA")); // 1
  // printf("ABA: %d\n", isPalindrome("ABA"));   // 1
  // printf("ABC: %d\n", isPalindrome("ABC"));   // 0

  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    char text[1001];
    scanf("%s", text);
    // printf("%s\n", text);

    printf("%d %d\n", isPalindrome(text), recursionCount);
  }

  return 0;
}