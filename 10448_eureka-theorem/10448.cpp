#include <iostream>
#include <string>

using namespace std;

int getDotCount(int n) {
  return n * (n + 1) / 2;
}

int main(void) {
  // freopen("example.txt", "r", stdin);

  int count;
  scanf("%d", &count);

  int triangles[count];
  for (int i = 0; i < count; ++i) {
    scanf("%d", &triangles[i]);
  }

  for (int i = 0; i < count; ++i) {
    bool isFound = false;
    int triangle = triangles[i];

    int j = 1;
    while (!isFound) {
      int firstDotCount = getDotCount(j);

      if (firstDotCount >= triangle) {
        break;
      }

      int k = 1;
      while (!isFound) {
        int secondDotCount = getDotCount(k);

        if (firstDotCount + secondDotCount >= triangle) {
          break;
        }

        int l = 1;
        while (!isFound) {
          int totalDotCount = firstDotCount + secondDotCount + getDotCount(l);
          // printf("%d, %d, %d, = %d =? %d\n", j, k, l, totalDotCount, triangle);

          if (totalDotCount == triangle) {
            isFound = true;

            break;
          }

          if (totalDotCount > triangle) {
            break;
          }

          ++l;
        }

        ++k;
      }

      ++j;
    }

    printf("%d\n", isFound);
  }

  return 0;
}