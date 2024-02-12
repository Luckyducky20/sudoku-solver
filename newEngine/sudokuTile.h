#ifndef SUDOKUTILE_H
#define SUDOKUTILE_H


#include <vector>

using std::vector;

class sudokuTile
{
  int tileNumber;
  bool tileNotes[10];


  public:
    sudokuTile();
    sudokuTile(int);
    bool isTaken();
    vector<int> getNotes();
    void placeNum(int);
    int getTileNum();

};

#endif
