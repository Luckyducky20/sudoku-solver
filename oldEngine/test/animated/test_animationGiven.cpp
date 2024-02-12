#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "boardNumber.h"
#include "sudokuUtils.h"


using std::cout;
using std::string;
using std::vector;
using std::cin;
int main()
{
  string clearCMD = "\033[2J";
  string moveCURS = "\033[H";
  int currentCount = 0;

  string boardString;

  string nextArg;
  while(cin >> nextArg)
  {
    boardString += nextArg;
  }
  
  vector<vector<boardNumber>> inputtedBoard = convertBoard(boardString);

  int layerShift = 0;
  int currentColorShift = 0;
  vector<string> rainbowBoard;
  // animating the board by printing it out very 10k count and going to the next frameColor
  cout << std::unitbuf;
  string currentLayer;
  while(currentCount<=1000)
  {
    currentCount++;
    
    for(int h=0;h<3;++h)
    {
      for(int i=0;i<15;++i)
      {
        if(h % 2==0)
        {
          layerShift = 0;
        }else if(h % 2==1)
        {
          layerShift = 3;
        }
        rainbowBoard = rainbowBoardSync(inputtedBoard,currentColorShift + layerShift);
        for(int j=0;j<6;++j)
        {
          currentLayer += rainbowBoard.at(i);
        }
        currentLayer += "\n";
      }
    }
    currentColorShift++;
    //cout << "\n\n";
    currentLayer += "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(40));
    cout << clearCMD << moveCURS;
    cout << currentLayer;
    currentLayer = "";
  }


  return 0;
}
