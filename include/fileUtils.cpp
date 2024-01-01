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

vector<string> getFileNames() {
  fs::path dir_path = "../inputtingBoards";
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

vector<string> getFileContents() {
  vector<string> returningVector;

  vector<string> fileNames = getFileNames();
  ifstream fileReader;
  for (string fileName : fileNames) {
    fileReader.open("../inputtingBoards/" + fileName);

    string fileString = "";
    string currentLine = "";

    while (getline(fileReader, currentLine)) {
      fileString += currentLine;
    }
    fileReader.close();
    returningVector.push_back(fileString);
  }
  return returningVector;
}

void generateBoardBatch() {
  vector<string> fileContents = getFileContents();
  ofstream fileWriter;
  ifstream fileReader;
  //int currentBatchNum;
  fileReader.open("../batches/batchCount");
  if (!fileReader) {
    fileWriter.open("../batches/batchCount");
    fileWriter << "0";
    fileWriter.close();
    fileReader.open("../batches/batchCount");
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
