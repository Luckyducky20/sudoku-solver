#include "sudokuTile.h"
#include <vector>

using std::vector;

sudokuTile::sudokuTile(int tileNum)
    : tileNumber(tileNum),
      tileNotes{true, true, true, true, true, true, true, true, true}
{
}

sudokuTile::sudokuTile()
    : tileNumber(0),
      tileNotes{false, true, true, true, true, true, true, true, true}
{
  tileNotes[0] = false;
}

bool sudokuTile::isTaken() { return tileNotes[0]; }

vector<int> sudokuTile::getNotes()
{
  vector<int> returningNumbers;
  for (int i = 1; i < 10; ++i) {
    if (tileNotes[i]) {
      returningNumbers.push_back(i);
    }
  }
  return returningNumbers;
}

void sudokuTile::placeNum(int tileNum)
{
  tileNumber = tileNum;
  tileNotes[0] = true;
}


int sudokuTile::getTileNum()
{
  if(tileNotes[0])
  {
    return tileNumber;
  }
  return -1;
}
  
