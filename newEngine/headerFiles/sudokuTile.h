#ifndef SUDOKUTILE_H
#define SUDOKUTILE_H


#include <vector>

using std::vector;

class sudokuTile
{
  bool placed;
  int tileNumber; // the number that is displayed on the board that is not a note
  int noteCount; // the amount of notes for this tile ( squareSize * squareSize )
  vector<bool> tileNotes;


  public:
    // constructors
    sudokuTile(); //default size of 3 for square size
    sudokuTile(int); // adds the notes with a square size as the input
    sudokuTile(int,int); // places inputNumber and ignores adding the notes

    void placeNum(int);
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
