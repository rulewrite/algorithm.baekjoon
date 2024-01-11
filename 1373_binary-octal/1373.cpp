#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main(void)
{
  // freopen("example.txt", "r", stdin);
  string input;
  cin >> input;

  string octal;

  int len = input.length();
  int i = len % 3;

  if (i != 0)
  {
    octal += std::to_string(std::bitset<3>(input.substr(0, i)).to_ulong());
  }

  while (i < len)
  {
    octal += std::to_string(std::bitset<3>(input.substr(i, 3)).to_ulong());
    i += 3;
  }

  cout << octal;

  return 0;
}