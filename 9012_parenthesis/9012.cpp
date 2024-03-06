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

  int n = 0;
  scanf("%d", &n);

  while (n--) {
    string str;
    cin >> str;

    // printf("%s\n", str.c_str());

    Stack stack(50);

    bool isUnderflow = false;
    for (size_t i = 0; i < str.size(); ++i) {
      char chr = str[i];

      if (chr == '(') {
        stack.push(0);
        continue;
      }

      if (stack.isEmpty()) {
        isUnderflow = true;
        break;
      }
      stack.pop();
    }

    if (isUnderflow) {
      printf("NO\n");
      continue;
    }

    printf(stack.isEmpty() ? "YES" : "NO");
    printf("\n");
  }

  return 0;
}