#include <iostream>

using namespace std;

class Stack {
private:
  static int const INIT_TOP = -1;
  int top;
  int elements[1000000];

public:
  Stack() {
    top = INIT_TOP;
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

  int n = 0;
  scanf("%d", &n);

  Stack stack;
  while (n--) {
    int ex = 0;

    scanf("%d", &ex);

    // printf("ex: %d ", ex);

    if (ex == 1) {
      int element = 0;
      scanf("%d", &element);
      stack.push(element);

      // printf("%d\n", element);

      continue;
    }

    if (ex == 2) {
      printf("%d\n", stack.pop());

      continue;
    }

    if (ex == 3) {
      printf("%d\n", stack.length());

      continue;
    }

    if (ex == 4) {
      printf("%d\n", stack.isEmpty());

      continue;
    }

    if (ex == 5) {
      printf("%d\n", stack.peek());

      continue;
    }
  }

  return 0;
}