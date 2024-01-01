#include "sudokuUtils.h"
#include "boardNumber.h"

#include <vector>
using std::vector,std::string,std::cout;

vector<string> formatBoard(string boardString)
{
  vector<string> newBoard;
  string currentLine = "";

  for(int i=0;i<9;++i)
  {
    if(i!=0 && i%3 == 0)
    {
      newBoard.push_back("---+---+---");
    }
    for(int j=0;j<9;++j)
    {
      if(j!=0 && j % 3==0)
      {
        currentLine += "|";
      }
      currentLine += boardString.at((i*9)+j);
    }
    newBoard.push_back(currentLine);
    currentLine = "";
  }
  return newBoard;
}



//vector<vector<boardNumber>> makeBoard(string inputtedBoard);
/*
vector<string> convertBoard(vector<vector<boardNumber>> inputtedBoard)
{
  vector<string> board;
  string currentLine;

  for(int i=0;i<9;++i)
  {
    if(i!=0 && i%3==0)
    {
      board.push_back("---+---+---");
    }
    for(int j=0;j<9;++j)
    {
      if(j!=0 && j%3 == 0)
      {
        currentLine += "|";
      }
      currentLine += inputtedBoard.at(i).at(j);
      //currentLine += board.at((i*9)+j);
    }
    board.push_back(currentLine);
  }
}

void printBoard(vector<vector<boardNumber>> inputtedBoard)
{
  vector<string> board = convertBoard(inputtedBoard);
  printBoard(board);

}
*/
void printBoard(vector<string> inputtedBoard)
{
  
  for(int i=0;i<inputtedBoard.size();++i)
  {
    cout << inputtedBoard.at(i) << "\n";
  }
}
