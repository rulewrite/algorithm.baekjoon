#include <iostream>

using namespace std;

// 세부구현을 클래스명에 담을 필요는 없지만...
class CircularQueue {
private:
  int capacity;
  int head;
  int rear;
  int* elements;

public:
  CircularQueue(int const SIZE) {
    head = -1;
    rear = -1;
    capacity = SIZE;
    elements = new int[capacity];
  }

  ~CircularQueue() {
    delete[] elements;
  }

  int size() {
    return rear - head;
  }

  bool isEmpty() {
    return head == -1 && rear == -1;
  }

  bool isFull() {
    return (rear + 1) % capacity == head;
  }

  void enqueue(int element) {
    if (isFull()) {
      return;
    }

    if (isEmpty()) {
      head = rear = 0;
    }
    else {
      rear = (rear + 1) % capacity;
    }

    elements[rear] = element;
  }

  int dequeue() {
    if (isEmpty()) {
      return -1;
    }

    int element = elements[head];
    if (head == rear) {
      head = rear = -1;
    }
    else {
      head = (head + 1) % capacity;
    }

    return element;
  }
};

int main(void) {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);

  CircularQueue circularQueue(n);
  for (int element = 1; element <= n; ++element) {
    // printf("%d", element);
    circularQueue.enqueue(element);
  }
  // printf("\n");

  while (true) {
    circularQueue.dequeue();
    int element = circularQueue.dequeue();

    if (circularQueue.isEmpty()) {
      printf("%d", element);
      return 0;
    }

    circularQueue.enqueue(element);
  }

  return 0;
}