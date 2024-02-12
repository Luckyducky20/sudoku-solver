#include "boardNumber.h"

#include <iostream>
#include <vector>

using std::cout,std::vector;


boardNumber::boardNumber(int newNumber)
  : number(newNumber)
{
  for(int i=0;i<10;++i)
  {
    numberNotes.push_back(true);
  }
}

boardNumber::boardNumber()
  : number(0)
{
  for(int i=0;i<10;++i)
  {
    numberNotes.push_back(true);
  }

  numberNotes[0] = false;
}

void boardNumber::removeNumberNote(int removingNum)
{
  numberNotes[removingNum] = false;
}

void boardNumber::setNumber()
{
  numberNotes[0] = true;
}

bool boardNumber::isNumberSet()
{
  return numberNotes[0];
}

int boardNumber::grabOneNote()
{
  for(int i=1;i<10;++i)
  {
    if(numberNotes[i])
    {
      return i;
    }
  }

  return -10;
}

vector<int> boardNumber::grabNotes()
{
  vector<int> allNotes;
  for(int i=1;i<10;++i)
  {
    if(numberNotes[i])
    {
      allNotes.push_back(i);
    }
  }
  return allNotes;
}

int boardNumber::grabNoteCount()
{
  int noteCount = 0;
  for(int i=1;i<10;++i)
  {
    if(numberNotes[i])
    {
      ++noteCount;
    }
  }
  return noteCount;
}

void boardNumber::printNotes()
{
  for(int i=0;i<10;++i)
  {
    cout << "[" << i << "]: " << numberNotes[i] << "\n";
  }
}

