#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
  return a.second < b.second;
};

int main(void)
{
  const int LOWER_CASE_GAP = abs('a' - 'A');
  string inputString;

  cin >> inputString;

  // 영문 외 필터링
  string english;

  for (int i = 0; i < (int)inputString.size(); i++)
  {
    // TODO: 변수 생명주기
    char inputChar = inputString[i];

    if (('A' <= inputChar && inputChar <= 'Z') || ('a' <= inputChar && inputChar <= 'z'))
    {
      english.push_back(inputChar);
    }
  }

  // 소문자 > 대문자
  for (int i = 0; i < (int)english.size(); i++)
  {
    char alphabet = english[i];

    if ('a' <= alphabet && alphabet <= 'z')
    {
      english[i] -= LOWER_CASE_GAP;
    }
  }

  // 알파벳 별 노출 수 집계
  // TODO: 맵이 정말 최선인가?
  map<char, int> alphabetToCount;

  for (int i = 0; i < (int)english.size(); i++)
  {
    char alphabet = english[i];

    if (alphabetToCount.count(alphabet) != 0)
    {
      alphabetToCount[alphabet] = alphabetToCount[alphabet] + 1;

      continue;
    }

    alphabetToCount[alphabet] = 1;
  }

  // Map을 배열로 변환
  vector<pair<char, int> > mapAsVector;
  for (const auto &pair : alphabetToCount)
  {
    mapAsVector.push_back(pair);
  }

  // 정렬에 사용할 비교 함수
  struct
  {
    bool operator()(const std::pair<char, int> &a, const std::pair<char, int> &b) const
    {
      return a.second > b.second;
    }
  } compareBySecond;

  // 배열을 count 값에 따라 정렬
  std::sort(mapAsVector.begin(), mapAsVector.end(), compareBySecond);

  if ((int)mapAsVector.size() == 1 || mapAsVector.at(0).second > mapAsVector.at(1).second)
  {
    printf("%c", mapAsVector.at(0).first);

    return 0;
  }

  printf("?");

  return 0;
}