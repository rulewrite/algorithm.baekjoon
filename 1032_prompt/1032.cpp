#include <iostream>

using namespace std;

int main(void) {
  // freopen("example.txt", "r", stdin);

  int fileCount;
  scanf("%d", &fileCount);

  char filenames[fileCount][50];

  for (int i = 0; i < fileCount; ++i) {
    scanf("%s", filenames[i]);
  }

  string baseFilename = filenames[0];
  int const LENGTH = (int)baseFilename.size();
  // printf("%s----", baseFilename.c_str());

  string pattern;
  for (int charIndex = 0; charIndex < LENGTH; ++charIndex) {
    char baseChar = baseFilename[charIndex];
    // printf("\n%c: ", baseChar);

    bool isMatched = true;
    for (int i = 1; i < fileCount; ++i) {
      string filename = filenames[i];
      char otherChar = filename[charIndex];

      // printf("%c ", otherChar);

      if (baseChar == otherChar) {
        continue;
      }

      isMatched = false;
      break;
    }

    pattern.push_back(isMatched ? baseChar : '?');
  }

  // printf("\n====\n");
  printf("%s", pattern.c_str());

  return 0;
}