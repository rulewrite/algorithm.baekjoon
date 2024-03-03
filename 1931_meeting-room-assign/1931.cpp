#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
  // 종료 시간이 같은 경우, 시작 시간이 더 빠른 회의를 먼저 오도록 설정
  if (a.second == b.second) {
    return a.first < b.first;
  }

  // 종료 시간이 더 빠른 회의를 먼저 오도록 설정
  return a.second < b.second;
}


int main(void) {
  // freopen("example.txt", "r", stdin);

  int meetingCount = 0;
  scanf("%d", &meetingCount);

  pair<int, int> meetings[meetingCount];
  for (int i = 0; i < meetingCount; ++i) {
    scanf("%d %d", &meetings[i].first, &meetings[i].second);
  }

  // 종료 시간을 기준으로 오름차순 정렬
  sort(meetings, meetings + meetingCount, compare);

  int count = 0;
  int lastTime = 0;
  for (int i = 0; i < meetingCount; ++i) {
    int start = meetings[i].first;
    int end = meetings[i].second;

    if (start >= lastTime) {
      // printf("%d %d\n", start, end);
      lastTime = end;
      ++count;
    }
  }

  printf("%d", count);

  return 0;
}