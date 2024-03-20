#include <iostream>

using namespace std;

class Deque {
private:
  struct Node {
    int element;
    struct Node* prev;
    struct Node* next;

    Node(int _element, Node* _prev, Node* _next) {
      element = _element;
      prev = _prev;
      next = _next;
    }
  };

  Node* head;
  Node* rear;
  int count;

public:
  Deque() {
    head = nullptr;
    rear = nullptr;
    count = 0;
  }

  int size() {
    return count;
  }

  bool isEmpty() {
    return count <= 0;
  }

  void pushFront(int element) {
    ++count;

    Node* node = new Node(element, nullptr, head);
    // head가 있다면 prev를 새로운 노드에 연결
    if (head != nullptr) {
      head->prev = node;
    }
    // head는 새 노드를 가리키도록
    head = node;

    // 최초 였다면 rear도 새 노드를 가리키도록
    if (rear == nullptr) {
      rear = node;
    }
  }

  void pushBack(int element) {
    ++count;

    Node* node = new Node(element, rear, nullptr);
    if (rear != nullptr) {
      rear->next = node;
    }
    rear = node;

    if (head == nullptr) {
      head = node;
    }
  }

  int popFront() {
    if (isEmpty()) {
      return -1;
    }

    --count;

    Node* poppedNode = head;
    // 추출할 노드의 next를 head로 할당
    head = poppedNode->next;
    // head가 널 포인터면 빈 것이므로 rear도 널 포인터로 할당
    if (head == nullptr) {
      rear = nullptr;
    }
    /**
     * head가 된 노드가 가리키던 prev 제거
     * 1. pushB < a
     * 2. pushB < b: a(h) <-> b(r)
     * 3. pop F > a: a    <-> b(hr)
     * 4. pop B > b
     * 했을 때 4번에서 rear = rear(b).prev(a)하는데, 해당 노드는 메모리 해제된 a 노드임.
     */
    else {
      head->prev = nullptr;
    }

    int result = poppedNode->element;
    delete poppedNode;
    return result;
  }

  int popBack() {
    if (isEmpty()) {
      return -1;
    }

    --count;

    Node* poppedNode = rear;
    rear = poppedNode->prev;
    if (rear == nullptr) {
      head = nullptr;
    }
    else {
      rear->next = nullptr;
    }

    int result = poppedNode->element;
    delete poppedNode;
    return result;
  }

  int front() {
    if (isEmpty()) {
      return -1;
    }

    return head->element;
  }

  int back() {
    if (isEmpty()) {
      return -1;
    }

    return rear->element;
  }
};

int main(void) {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);

  Deque deque;
  while (n--) {
    int ex;
    scanf("%d", &ex);
    // printf("--ex: %d\n", ex);

    if (ex == 1) {
      int element = 0;
      scanf("%d", &element);
      deque.pushFront(element);

      continue;
    }

    if (ex == 2) {
      int element = 0;
      scanf("%d", &element);
      deque.pushBack(element);

      continue;
    }

    if (ex == 3) {
      printf("%d\n", deque.popFront());

      continue;
    }

    if (ex == 4) {
      printf("%d\n", deque.popBack());

      continue;
    }

    if (ex == 5) {
      printf("%d\n", deque.size());

      continue;
    }

    if (ex == 6) {
      printf("%d\n", deque.isEmpty());

      continue;
    }

    if (ex == 7) {
      printf("%d\n", deque.front());

      continue;
    }

    if (ex == 8) {
      printf("%d\n", deque.back());

      continue;
    }
  }

  return 0;
}