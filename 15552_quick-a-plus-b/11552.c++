#include <stdio.h>

int main(void)
{
  // freopen("example.txt", "r", stdin);
  int T, a, b;

  scanf("%d", &T);

  for (int i = 0; i < T; i++)
  {
    scanf("%d %d", &a, &b);
    printf("%d\n", a + b);
  }

  return 0;
}