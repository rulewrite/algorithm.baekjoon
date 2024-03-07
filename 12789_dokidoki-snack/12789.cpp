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

  int COUNT;
  scanf("%d", &COUNT);

  Stack stack(1e3);
  int order = 1;

  while (COUNT--) {
    int n;
    scanf("%d", &n);
    // printf("%d", n);

    if (order == n) {
      ++order;
      continue;
    }

    while (order == stack.peek()) {
      ++order;
      stack.pop();
    }

    stack.push(n);
  }

  while (!stack.isEmpty()) {
    if (order == stack.pop()) {
      ++order;
      continue;
    }

    printf("Sad");
    return 0;
  }

  printf("Nice");
  return 0;
}