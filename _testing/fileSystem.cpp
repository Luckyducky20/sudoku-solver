#include "../myUtils/consoleColors.h"
#include "../myUtils/fileUtils.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

using std::string, std::ifstream, std::vector, std::cout;
namespace fs = std::filesystem;

int main() {
  fs::path dir_path = "../inputtingBoards";
  int file_count = 0;

  vector<string> fileNamesInDir = getFileNames();
  cout << fileNamesInDir.size() << " files in directory:\n";

  consColors colorPal;

  for (string fileName : fileNamesInDir) {
    file_count++;

    string currentDirectory = "../inputtingBoards/";
    currentDirectory += fileName;
    ifstream currentFile;
    currentFile.open(currentDirectory);

    if (!currentFile) {
      cout << "File not found: " << fileName << "\n";
      continue;
    }

    string currentFileString = "";
    string currentLine;

    // this is to keep track of how many numbers we have read in. If the value
    // is less then 81, then we don't generate the board. We have to check the
    // charCount because users can also input boards manually instead of
    // generating them.
    int charCount = 0;
    while (getline(currentFile, currentLine)) {
      charCount += currentLine.length();
      currentFileString += currentLine;
    }
    if (charCount < 81) {
      cout << colorPal.redF << "Warning!\n"
           << colorPal.resetColor << colorPal.yellowF << fileName
           << " is less then the board size and will be ignored!\n"
           << colorPal.resetColor;
    } else {
      cout << colorPal.greenF << fileName << "\n" << colorPal.resetColor;
      cout << currentFileString << "\n";
    }
  }

  return 0;
}
