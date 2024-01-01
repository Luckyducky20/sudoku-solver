#ifndef SUDOKU_UTILS_H
#define SUDOKU_UTILS_H

#include "boardNumber.h"
#include <iostream>
#include <vector>
using std::vector,std::string;


void printBoard(vector<string> inputtedBoard);
//this will not work properly with a rainbow baord, please use printBoard for a vector<string> that holds a rainbow board
//the reason why it will not work is because of an indexing issue
void printColoredBoard(vector<string> inputtedBoard);
//prints a board with a custom inside color
void printCCBoard(vector<string> inputtedBoard,string colorCode);

string getLayerSlice(vector<vector<boardNumber>>,int);
string getLayerSliceC(vector<vector<boardNumber>>,int,string);

vector<string> getStringBoard(string boardString);
vector<string> getStringBoardVec(vector<vector<boardNumber>>);
vector<string> getCCBoard(vector<string>,string);
vector<string> highlightedBoard(vector<vector<boardNumber>>,string,string);

// returns a board that has a rainbow outside and inside
vector<string> rainbowBoard(vector<vector<boardNumber>>);
// returns a board that has a rainbow inside grid
vector<string> rainbowInner(vector<vector<boardNumber>>);
// returns a board that has a rainbow highlight
vector<string> rainbowHighlight(vector<vector<boardNumber>>);

// returns a board that has a rainbow outside and inside, but the rainbow that the board has is the same as the ring around the board for each layer
vector<string> rainbowBoardSync(vector<vector<boardNumber>>,int);
vector<string> rainbowBoardSyncIn(vector<vector<boardNumber>>,int);
vector<string> rainbowBoardSyncOut(vector<vector<boardNumber>>,int);

vector<vector<boardNumber>> convertBoard(string boardString);
vector<vector<vector<boardNumber>>> convertBoards(string boardStrings);

#endif
