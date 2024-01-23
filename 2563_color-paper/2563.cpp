#include <iostream>
#include <string>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int paperCount;
  scanf("%d", &paperCount);

  int paperPositions[paperCount][2];
  for (int i = 0; i < paperCount; ++i) {
    int xMargin;
    int yMargin;
    scanf("%d %d", &xMargin, &yMargin);

    paperPositions[i][0] = xMargin;
    paperPositions[i][1] = yMargin;
  }

  int const PAPER_SIZE = 10;
  int totalArea = (PAPER_SIZE * PAPER_SIZE) * paperCount;

  for (int i = 0; i < paperCount; ++i) {
    int aLeftX = paperPositions[i][0];
    int aBottomY = paperPositions[i][1];

    int aRightX = aLeftX + PAPER_SIZE;
    int aTopY = aBottomY + PAPER_SIZE;

    for (int j = i + 1; j < paperCount; ++j) {
      int bLeftX = paperPositions[j][0];
      int bBottomY = paperPositions[j][1];

      int bRightX = bLeftX + PAPER_SIZE;
      int bTopY = bBottomY + PAPER_SIZE;

      // https://wikibook.co.kr/article/collision-detection-and-object-representation-in-2d-2/
      bool isOverlap =
        aLeftX < bRightX && // a의 좌측 x가 b의 우측 x보다 항상 좌측에 있어야 한다.
        aRightX > bLeftX && // a의 우측 x가 b의 좌측 x보다 항상 우측에 있어야 한다.
        aBottomY < bTopY && // a의 하단 y가 b의 상단 y보다 항상 하단에 있어야 한다.
        aTopY > bBottomY;   // a의 상단 y가 b의 하단 y보다 항상 상단에 있어야 한다.

      if (!isOverlap) {
        continue;
      }

      // https://tibyte.kr/228
      // https://wonsang0514.tistory.com/38
      int overlapLeftX = aLeftX > bLeftX ? aLeftX : bLeftX;           // 좌측 x는 두 사각형의 좌측 x중 큰 것 (먼 것)
      int overlapRightX = aRightX < bRightX ? aRightX : bRightX;      // 우측 x는 두 사각형의 우측 x중 작은 것 (가까운 것)
      int overlapBottomY = aBottomY > bBottomY ? aBottomY : bBottomY; // 하단 y는 두 사각형의 하단 y중 큰 것 (먼 것)
      int overlapTopY = aTopY < bTopY ? aTopY : bTopY;                // 상단 y는 두 사각형의 상단 y중 작은 것 (가까운 것)

      totalArea -= (overlapRightX - overlapLeftX) * (overlapTopY - overlapBottomY);
    }
  }

  printf("%d", totalArea);

  return 0;
}
