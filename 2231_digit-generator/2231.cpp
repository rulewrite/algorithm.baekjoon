#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  // freopen("example.txt", "r", stdin);
  int input;
  cin >> input;

  for (int i = 0; i < input; i++)
  {
    int sum = i;

    int num = i;
    while (num != 0)
    {
      sum += num % 10;
      num /= 10;
    }

    if (sum == input)
    {
      cout << i;
      return 0;
    }
  }

  cout << 0;
  return 0;
}