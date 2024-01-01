#include "fileUtils.h"
#include "boardNumber.h"
#include "sudokuUtils.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <vector>

using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

namespace fs = std::filesystem;

vector<string> getFileNames(string path) {
  fs::path dir_path = path;
  vector<string> fileNames;
  for (const auto &entry : fs::directory_iterator(dir_path)) {
    if (entry.is_regular_file()) {
      fileNames.push_back(entry.path().filename());
    }
  }

  return getSpecificFileNames(dir_path);
}

vector<string> getSpecificFileNames(fs::path dir_path) {
  vector<string> fileNames;
  for (const auto &entry : fs::directory_iterator(dir_path)) {
    if (entry.is_regular_file()) {
      fileNames.push_back(entry.path().filename());
    }
  }

  return fileNames;
}

vector<string> getFileContents(string path) {
  vector<string> returningVector;

  vector<string> fileNames = getFileNames(path);
  ifstream fileReader;
  for (string fileName : fileNames) {
    fileReader.open(path + fileName);

    string fileString = "";
    string currentLine = "";
    while (getline(fileReader, currentLine)) {
			// this is to remove the \r bit which can cause some issues
			// not sure if this is just on WSL(windows subsystem for linux) though.
			currentLine.pop_back();
      fileString += currentLine;
    }
    fileReader.close();
    returningVector.push_back(fileString);
  }
  return returningVector;
}

void generateBoardBatch(string inputDirectory, string outputDirectory, string batchCountDirectory) {
  vector<string> fileContents = getFileContents(inputDirectory);
  ofstream fileWriter;
  ifstream fileReader;
  //int currentBatchNum;
  fileReader.open(batchCountDirectory + "batchCount");
  if (!fileReader) {
    fileWriter.open(batchCountDirectory + "batchCount");
    fileWriter << "0";
    fileWriter.close();
    fileReader.open(batchCountDirectory + "batchCount");
  }

  fileReader.close();
  cout << "here\n";
  string batchCounter = "";

  vector<vector<vector<boardNumber>>> boardHolder;
  for (string fileContent : fileContents) {
    if (fileContent.length() < 81) {
      continue;
    }
    boardHolder.push_back(convertBoard(fileContent));
  }

  for (vector<vector<boardNumber>> board : boardHolder) {
    printBoard(rainbowBoardSync(board, 0));
    // printColoredBoard(getStringBoardVec(board));
    cout << "\n";
  }
}
