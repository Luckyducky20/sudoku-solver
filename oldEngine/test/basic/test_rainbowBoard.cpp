#include <iostream>
#include <fstream>
#include <vector>
#include "consoleColors.h"

#include "sudokuUtils.h"

using std::cin,std::vector,std::ofstream,std::ifstream,std::stoi,std::string,std::cout;
using std::to_string;

int main()
{
  string board;
  cout << "here\n";
  string nextArg;

  // reading in the new board
  while(cin >> nextArg)
  {
    board += nextArg;
  }
  vector<vector<boardNumber>> testBoard = convertBoard(board);
  cout << "testBoard width: " << testBoard.size() << "\n";
  cout << "testBoard firstNum: " << to_string(testBoard.at(0).at(0).number) << "\n";
  vector<string> newBoard;
  newBoard = getStringBoard(board);
  //printBoard(newBoard);
  cout << "next test: \n";
  //printColoredBoard(newBoard);

  vector<boardNumber> blankRow;
  boardNumber testNum;
  for(int i=0;i<9;++i)
  {
    blankRow.push_back(testNum);
  }
  cout << "here\n";
  vector<string> stringBoard = getStringBoardVec(testBoard);
  for(int i=0;i<11;++i)
  {
    cout << getLayerSlice(testBoard,i) << "\n";
  }

  consColors colorPal;
  string colors;
  colors += colorPal.whiteB;
  colors += colorPal.cyanF;
  printCCBoard(stringBoard,colorPal.redF);
  printCCBoard(stringBoard,colorPal.magentaF);
  printCCBoard(stringBoard,colors);
  
  vector<string> rainbowFullBoard = rainbowBoard(testBoard);
  vector<string> rainbowInBoard = rainbowInner(testBoard);
  vector<string> rainbowOutBoard = rainbowHighlight(testBoard);
  vector<string> rainbowBoardSyncedCol = rainbowBoardSync(testBoard);
  
  for(int h=0;h<4;++h)
  {
    if(h == 0)
    {
      for(int i=0;i<15;++i)
      {
        for(int j=0;j<2;++j)
        {
          cout << rainbowFullBoard.at(i) << " ";
        }
        cout << "\n";
      }
      cout << "\n\n";
    }else if(h==1)
    {
      for(int i=0;i<15;++i)
      {
        for(int j=0;j<3;++j)
        {
          cout << rainbowInBoard.at(i) << " ";
        }
        cout << "\n";
      }
      cout << "\n\n";
    }else if(h == 2)
    {
      for(int i=0;i<15;++i)
      {
        for(int j=0;j<4;++j)
        {
          cout << rainbowOutBoard.at(i) << " ";
        }
        cout << "\n";
      }
      cout << "\n\n";
    }else
    {
      for(int i=0;i<15;++i)
      {
        for(int j=0;j<3;++j)
        {
          cout << rainbowBoardSyncedCol.at(i) << " ";
        }
        cout << "\n";
      }
      cout << "\n\n";
    }
  }

  return 0;
}
  


