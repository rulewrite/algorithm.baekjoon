#include <iostream>

using namespace std;

struct Balloon {
  int order;
  int step;

  Balloon(int _order, int _step) {
    order = _order;
    step = _step;
  }
};


template<typename T>
class Deque {
private:
  struct Node {
    T element;
    struct Node* prev;
    struct Node* next;

    Node(const T& _element, Node* _prev, Node* _next)
      : element(_element), prev(_prev), next(_next) {}
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

  void pushFront(const T& element) {
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

  void pushBack(const T& element) {
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

  T popFront() {
    if (isEmpty()) {
      printf("\n~~ popFront exit: Empty~~ \n");
      exit(1);
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

    T result = poppedNode->element;
    delete poppedNode;
    return result;
  }

  T popBack() {
    if (isEmpty()) {
      printf("\n~~ popBack exit: Empty~~ \n");
      exit(1);
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

    T result = poppedNode->element;
    delete poppedNode;
    return result;
  }

  T front() {
    if (isEmpty()) {
      printf("\n~~ front exit: Empty~~ \n");
      exit(1);
    }

    return head->element;
  }

  T back() {
    if (isEmpty()) {
      printf("\n~~ back exit: Empty~~ \n");
      exit(1);
    }

    return rear->element;
  }
};

int main(void) {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);

  Deque<Balloon> deque;
  int order = 0;

  while (n--) {
    int element = 0;
    scanf("%d", &element);
    // printf("%d\n", element);
    deque.pushBack(Balloon(++order, element));
  }

  // printf("%d\n", deque.size());

  while (!deque.isEmpty()) {
    Balloon balloon = deque.popFront();
    printf("%d ", balloon.order);
    // printf("%d\n", balloon.step);

    // step은 0일 수 없음.
    int step = balloon.step;

    if (step > 0) {
      // 3: 2 > 1
      while (--step && !deque.isEmpty()) {
        deque.pushBack(deque.popFront());
      }

      continue;
    }

    // -3: -3 > -2 > -1
    while (++step <= 0 && !deque.isEmpty()) {
      deque.pushFront(deque.popBack());
    }
  }

  return 0;
}