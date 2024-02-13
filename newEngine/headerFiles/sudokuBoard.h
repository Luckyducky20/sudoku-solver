#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include "sudokuTile.h"
#include <vector>

class sudokuBoard
{
  vector<vector<sudokuTile>> board;
  int squareSize(3); 

  public:

    sudokuBoard(sudokuTile[9][9])
      : board(inputTable)
    {
    }
    void setSquareSize(int); 
    int getSquareSize(int); 
    void addNumberNotes();
    int getSpaceCount(); // returns the amount of spaces that are empty still aka don't have a number placed in them
    void columnNotes(int,int); // update Notes for this
    void rowNotes(int,int);
    void squareNotes(int,int);

    bool boardContainsNoteCount(int);
    vector<int> findLowestNoteCount(int);
    void addFrontNumber(int,int,int);
    bool isValidBoard();
    bool isBoardSolved();
    // ^-- this could check if the space count is 0, if its not, then its not solved
    // store the amount of empty spaces somewhere instead of having to recount it everytime?
    

}

#endif
