#include "sudokuTile.h"
#include <vector>

using std::vector;


sudokuTile::sudokuTile()
  : placed(false),
    noteCount(9),
    tileNumber(0)
{
  for(int i=0;i<9;++i)
  {
    tileNotes.push_back(true);
  }
}
sudokuTile::sudokuTile(int squareSize,int tileNum)
   :  placed(true),
      noteCount(squareSize*squareSize),
      tileNumber(tileNum)
{
}

sudokuTile::sudokuTile(int squareSize) // squareSize**2 is note count for square,column and or row
    : placed(false),
      noteCount(squareSize * squareSize),
      tileNumber(0)
{
  for(int i=0;i<noteCount;++i)
  {
    tileNotes.push_back(true);
  }
}

bool sudokuTile::isTaken() { return placed; }

int sudokuTile::getOneNote() // get the last note available or just grab one of the available notes
{
  for(int i=0;i<noteCount;++i)
  {
    if(tileNotes.at(i))
    {
      return (i+1);
    }
  }
  return -1;
}

vector<int> sudokuTile::getNotes()
{
  vector<int> returningNumbers;
  for (int i = 0; i < noteCount; ++i)
  {
    if (tileNotes.at(i)) 
    {
      returningNumbers.push_back(i+1);
    }
  }
  return returningNumbers;
}

bool sudokuTile::isOneNote(){return noteCount == 1;}

void sudokuTile::setNum(int tileNum)
{
  tileNumber = tileNum;
  placed = true;
}


int sudokuTile::getTileNum()
{
  if(placed)
  {
    return tileNumber;
  }
  return -1;
}
  
void sudokuTile::removeNote(int removedNote)
{
  tileNotes.at(removedNote-1) = false;
  noteCount--;
}

int sudokuTile::getNoteCount()
{
  return noteCount;
}


bool sudokuTile::canBeHere(int number)
{
  return tileNotes.at(number-1);
}
