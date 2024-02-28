#include <stdio.h>
#include <string.h>

using namespace std;

void recursion(int n, int count) {
  int const PRIFIX_COUNT = count * 4;
  char prefix[PRIFIX_COUNT];
  memset(prefix, '_', PRIFIX_COUNT);
  prefix[PRIFIX_COUNT] = '\0';

  printf("%s\"재귀함수가 뭔가요?\"\n", prefix);

  if (n <= 0) {
    printf("%s\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", prefix);
  }
  else {
    printf("%s\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", prefix);
    printf("%s마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", prefix);
    printf("%s그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", prefix);

    recursion(n - 1, count + 1);
  }

  printf("%s라고 답변하였지.\n", prefix);
}

int main() {
  // freopen("example.txt", "r", stdin);

  int n = 0;
  scanf("%d", &n);

  printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
  recursion(n, 0);

  return 0;
}