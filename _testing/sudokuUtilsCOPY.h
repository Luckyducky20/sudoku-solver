#ifndef SUDOKU_UTILS_H
#define SUDOKU_UTILS_H

#include "boardNumber.h"
#include <vector>
using std::vector,std::string;

vector<string> formatBoard(string boardString);
//vector<vector<boardNumber>> makeBoard(string inputtedBoard);
//vector<vector<boardNumber>> makeBoard(vector<string> inputtedBoard);
//
//*vector<string> getStringBoardVec(vector<vector<boardNumber>> inputtedBoard);
//
//*void printBoard(vector<vector<boardNumber>> inputtedBoard);
void printBoard(vector<string> inputtedBoard);





#endif
