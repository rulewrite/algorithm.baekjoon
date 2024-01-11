#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  // freopen("example.txt", "r", stdin);

  const int COUNT = 9;
  int dwarfHeights[COUNT];
  for (int i = 0; i < COUNT; ++i)
  {
    scanf("%d", &dwarfHeights[i]);
  }

  // 선택정렬
  for (int i = 0; i < COUNT - 1; ++i)
  {
    int minIdx = i;

    for (int j = i + 1; j < COUNT; ++j)
    {
      if (dwarfHeights[j] < dwarfHeights[minIdx])
      {
        minIdx = j;
      }
    }

    int min = dwarfHeights[minIdx];
    dwarfHeights[minIdx] = dwarfHeights[i];
    dwarfHeights[i] = min;
  }

  // 토탈 값 구하기
  int totalSum = 0;
  for (int i = 0; i < COUNT; ++i)
  {
    totalSum += dwarfHeights[i];
  }

  // 두 명을 빼서 100이 되는 난쟁이 출력
  const int TOTAL_HEIGHT = 100;
  for (int i = 0; i < COUNT - 1; ++i)
  {
    int current = dwarfHeights[i];

    for (int j = i + 1; j < COUNT; ++j)
    {
      int sum = current + dwarfHeights[j];

      if (totalSum - sum == TOTAL_HEIGHT)
      {
        for (int k = 0; k < COUNT; ++k)
        {
          if (k == i || k == j)
          {
            continue;
          }

          printf("%d\n", dwarfHeights[k]);
        }

        return 0;
      }
    }
  }

  return 0;
}