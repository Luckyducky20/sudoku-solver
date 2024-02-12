#include <iostream>
#include <vector>
#include "../../include/fileUtils.h"

using std::cout;
using std::vector;
using std::string;

int main()
{
  vector<string> fileContents = getFileContents("../../inputtingBoards/");

  for(string fileContent: fileContents)
  {
    cout << "[" << fileContent.length() << "]: " << fileContent << "\n";
  }
	cout << "end of strings\n";

  return 0;
}
