#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  // freopen("example.txt", "r", stdin);

  string octalString;
  cin >> octalString;

  // printf("%lu\n", octalString.length());

  string binary;
  int const LENGTH = (int)octalString.size();

  for (int i = 0; i < LENGTH; ++i) {
    char octalChar = octalString[i];
    int octal = atoi(&octalChar);

    // printf("%d", octal);

    if (octal >= 4) {
      octal -= 4;
      binary.push_back('1');
    }
    else if (binary.size() > 0) {
      binary.push_back('0');
    }

    if (octal >= 2) {
      octal -= 2;
      binary.push_back('1');
    }
    else if (binary.size() > 0) {
      binary.push_back('0');
    }

    if (octal == 1) {
      binary.push_back('1');
    }
    else {
      binary.push_back('0');
    }
  }

  printf("%s", binary.c_str());

  return 0;
}