#include <iostream>

using namespace std;

class Stack {
private:
  static int const INIT_TOP = -1;
  int top;
  int* elements;

public:
  Stack(int const MAX_SIZE) {
    top = INIT_TOP;
    elements = new int[MAX_SIZE];
  }

  ~Stack() {
    delete[] elements;
  }

  bool isEmpty() {
    return top <= INIT_TOP;
  }

  int length() {
    return top + 1;
  }

  void push(int element) {
    elements[++top] = element;
  }

  int pop() {
    if (isEmpty()) {
      return -1;
    }

    return elements[top--];
  }

  int peek() {
    if (isEmpty()) {
      return -1;
    }

    return elements[top];
  }
};

int main(void) {
  // freopen("example.txt", "r", stdin);

  string str;
  cin >> str;

  Stack stack(1e5);
  int stickCount = 0;
  for (size_t i = 0; i < str.size(); ++i) {
    char chr = str[i];
    // printf("%d: %c\n", stickCount, chr);

    if (chr == '(') {
      stack.push(1);
      continue;
    }
    stack.pop();

    // 이전이 여는 괄호라면 레이저 현재 쇠 막대기의 숫자를 더함
    bool isLaser = str[i - 1] == '(';
    if (isLaser) {
      stickCount += stack.length();
      continue;
    }

    // 이전이 닫는 괄호 였다면 쇠 막대기 하나가 끝난 것으로 하나 더함.
    ++stickCount;
  }

  printf("%d", stickCount);


  return 0;
}