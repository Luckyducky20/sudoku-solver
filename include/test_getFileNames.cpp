#include <iostream>
#include <vector>
#include "fileUtils.h"

using std::cout;
using std::string;
using std::vector;

int main()
{
  vector<string> fileNames = getFileNames();

  cout << "Files inside of inputtingBoards: \n";

  for(string fileName: fileNames)
  {
    cout << fileName << "\n";
  }



  return 0;
}
