#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "../../include/boardNumber.h"
#include "../../include/sudokuUtils.h"

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
  vector<vector<vector<boardNumber>>> inputtedBoards = convertBoards(boardString);
  int layerShift = 0;
  int currentColorShift = 0;
  vector<string> rainbowBoard;
  // animating the board by printing it out very 10k count and going to the next frameColor
  cout << std::unitbuf;
  string currentLayer;

  // 1000 color changes
  while(currentCount<=1000)
  {
    currentCount++;
   	// rows 
    for(int h=0;h<3;++h)
    {
	  // printing out the whole sudoku grid with a ring around it
      for(int i=0;i<15;++i)
      {
		
		// this specifies what shift is needed between two rows of boards to match the color sequence
        if(h % 2==0)
        {
          layerShift = 0;
        }else if(h % 2==1)
        {
          layerShift = 3;
        }
		for(unsigned int m=0;m<inputtedBoards.size();++m)
		{
		
        	rainbowBoard = rainbowBoardSync(inputtedBoards.at(m),currentColorShift + layerShift);
			// building the line horizontally with all the other boards
			// column count
       		//for(int j=0;j<2;++j)
        	//{
          	currentLayer += rainbowBoard.at(i);
          	currentLayer += "  ";
        	//}
		}
        currentLayer += "\n";
      }
		// adding some spacing between the rows of boards
		currentLayer += "\n";
    }
    currentColorShift++;
    currentLayer += "\n\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(40));
    cout << clearCMD << moveCURS;
    cout << currentLayer;
    currentLayer = "";
  }
  cout << "You have reached the end of this test animation! :)\n";


  return 0;
}
