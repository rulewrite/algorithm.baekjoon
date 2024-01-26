#include <iostream>

using namespace std;

int const LENGTH = 1e4;

bool isSelfNumbers(int goals) {
  for (int underNum = 1; underNum < goals; ++underNum) {
    int sum = underNum;

    int i = underNum;
    while (i) {
      sum += i % 10;
      i /= 10;
    }

    if (sum == goals) {
      return false;
    }
  }

  return true;
}

int main(void) {

  for (int i = 1; i < LENGTH;++i) {
    if (isSelfNumbers(i)) {
      printf("%d\n", i);
    }
  }

  return 0;
}