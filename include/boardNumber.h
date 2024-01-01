#ifndef BOARDNUMBER_H
#define BOARDNUMBER_H

#include <vector>
using std::vector;

struct boardNumber
{
  int number;
  vector<bool> numberNotes;
  
  boardNumber(int);
  boardNumber();

  void removeNumberNote(int);
  void setNumber();
  bool isNumberSet();
  int grabOneNote();
  vector<int> grabNotes();
  int grabNoteCount();
  
  void printNotes();
};

#endif
