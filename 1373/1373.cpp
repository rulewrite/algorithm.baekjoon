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

  for (int i = input.length(); i >= 0; i -= 3)
  {
    std::string sliced = input.substr(std::max(i - 3, 0), i);

    if (sliced.empty())
    {
      break;
    }

    int binary = std::bitset<3>(sliced).to_ulong();
    octal = std::to_string(binary) + octal;
  }

  cout << octal;

  return 0;
}