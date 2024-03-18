#include <iostream>

using namespace std;

class Queue {
private:
  static int const INIT = -1;
  int head;
  int tail;
  int* elements;

public:
  Queue(int const SIZE) {
    head = INIT;
    tail = INIT;
    elements = new int[SIZE];
  }

  ~Queue() {
    delete[] elements;
  }

  bool isEmpty() {
    return head == tail;
  }

  int size() {
    return tail - head;
  }

  void push(int element) {
    elements[++tail] = element;
  }

  int pop() {
    if (isEmpty()) {
      return -1;
    }

    return elements[++head];
  }

  int front() {
    if (isEmpty()) {
      return -1;
    }

    return elements[head + 1];
  }

  int back() {
    if (isEmpty()) {
      return -1;
    }

    return elements[tail];
  }
};

int str_compare(char* str1, const char* str2) {
  int idx = 0;

  while (str1[idx] && str1[idx] == str2[idx]) {
    idx++;
  }

  if (str1[idx]) return 0; // str1이랑 str2가 다르다
  else return 1; // str1이랑 str2가 같다.
}

int main(void) {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);

  Queue queue(2e6);
  while (n--) {
    char ex[10];
    scanf("%s ", ex);

    // printf("ex: %s ", ex.c_str());

    if (str_compare(ex, "push")) {
      int element = 0;
      scanf("%d", &element);
      queue.push(element);

      continue;
    }

    if (str_compare(ex, "pop")) {
      printf("%d\n", queue.pop());

      continue;
    }

    if (str_compare(ex, "size")) {
      printf("%d\n", queue.size());

      continue;
    }

    if (str_compare(ex, "empty")) {
      printf("%d\n", queue.isEmpty());

      continue;
    }

    if (str_compare(ex, "front")) {
      printf("%d\n", queue.front());

      continue;
    }

    if (str_compare(ex, "back")) {
      printf("%d\n", queue.back());

      continue;
    }
  }

  return 0;
}