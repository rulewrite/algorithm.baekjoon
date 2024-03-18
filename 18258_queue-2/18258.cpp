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

int main(void) {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);

  Queue queue(2e6);
  while (n--) {
    string ex;
    cin >> ex;

    // printf("ex: %s ", ex.c_str());

    if (ex == "push") {
      int element = 0;
      scanf("%d", &element);
      queue.push(element);

      continue;
    }

    if (ex == "pop") {
      printf("%d\n", queue.pop());

      continue;
    }

    if (ex == "size") {
      printf("%d\n", queue.size());

      continue;
    }

    if (ex == "empty") {
      printf("%d\n", queue.isEmpty());

      continue;
    }

    if (ex == "front") {
      printf("%d\n", queue.front());

      continue;
    }

    if (ex == "back") {
      printf("%d\n", queue.back());

      continue;
    }
  }

  return 0;
}