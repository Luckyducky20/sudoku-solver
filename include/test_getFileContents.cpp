#include <iostream>
#include <vector>
#include "fileUtils.h"

using std::cout;
using std::vector;
using std::string;

int main()
{
  vector<string> fileContents = getFileContents();

  for(string fileContent: fileContents)
  {
    cout << fileContent << "\n\n";
  }

  return 0;
}
