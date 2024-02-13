#ifndef SUDOKUTILE_H
#define SUDOKUTILE_H


#include <vector>

using std::vector;

class sudokuTile
{
  bool placed;
  int tileNumber;
  int noteCount;
  vector<bool> tileNotes;


  public:
    // constructors
    sudokuTile(); 
    sudokuTile(int); // adds the notes with a square size as the input
    sudokuTile(int,int); // places inputNumber and ignores adding the notes

    void setNum(int);
    void removeNote(int);

    int getTileNum();
    int getNoteCount();
    int getOneNote();
    vector<int> getNotes();

    bool canBeHere(int); // checks if a note is available or not
    bool isTaken();
    bool isOneNote();
};

#endif
