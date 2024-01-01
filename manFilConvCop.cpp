#include <iostream>
#include <fstream>
#include <vector>

#include "_testing/sudokuUtils.h"

using std::cin,std::vector,std::ofstream,std::ifstream,std::stoi,std::string,std::cout;

int main()
{
  vector<string> newBoard;
  string board;
  string nextArg;

  // reading in the new board
  while(cin >> nextArg)
  {
    board += nextArg;
  }
  
  string currentLine;

  newBoard = formatBoard(board);
  printBoard(newBoard);
  cout << "here\n";
  return 0;
}
  //cout << newBoard;
  /*
  int boardNumber = 0;
  ifstream readingFile;
  readingFile.open("boardCounting/boardNum.txt");
  if(!readingFile)
  {
    cout << "File not found\n";
    return 1;
  }

  string firstLine;
  getline(readingFile,firstLine);
  readingFile.close();

  boardNumber = stoi(firstLine);

  boardNumber++;
  string newFileName = "boards/0" + std::to_string(boardNumber) + "converted.txt";
  ofstream oStreamBoard;

  oStreamBoard.open("boardCounting/boardNum.txt");
  oStreamBoard << boardNumber << "\n";
  oStreamBoard.close();

  ofstream outPutBoardFile;
  outPutBoardFile.open(newFileName);
  outPutBoardFile << newBoard;
  outPutBoardFile.close();
 */ 
  


