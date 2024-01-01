#include <iostream>
#include <vector>
#include "fileUtils.h"

using std::cout;
using std::vector;
using std::string;

int main()
{
  generateBoardBatch();
  vector<string> fileNames = getFileNames();
  for(string fileName: fileNames)
  {
    cout << fileName << "\n";
  }



  return 0;
}
