#include "sudokuTile.h"
#include "sudokuBoard.h" 
#include <iostream>
#include <vector>




sudokuBoard::sudokuBoard(vector<vector<sudokuTile>> newBoard,int squareLength)
  : board(newBoard);
    squareSize(squareLength)
{
}

void sudokuBoard::setSquareSize(int newSize)
{
  squareSize(newSize);
}

int sudokuBoard::getSquareSize(int newSize)
{
  return squareSize;
}

void sudokuBoard::addNumberNotes()
{
  for(int y=0;y<(squareSize*squareSize);++y)
  {
    for(int x=0;x<(squareSize*squareSize);++x)
    {
      columnNotes(y,x);
      rowNotes(y,x);
      squareNotes(y,x);
    }
  }
}


int sudokuBoard::getSpaceCount()
{
  int sideLength(squareSize * squareSize);
  int count(sideLength * sideLength); // subtracting to reduce operations earlier on in the board during a solve
  for(int y=0;y<sideLength;++y)
  {
    for(int x=0;x<sideLength;++x)
    {
      if(board.at(y).at(x).isTaken())
      {
        count--;
      }
    }
  }
  return count;
}

void sudokuBoard::columnNotes(int y,int x)
{
  int currentNum(board.at(y).at(x).tileNumber);
  if(!board.at(y).at(x).isTaken()) // if a number isn't set, then there is nothing that needs updating
  {
    return;
  }
  

  for(int fY=0;fY<(squareSize * squareSize);++fY)
  {

    if(board.at(fY).at(x).isTaken())
    {
      continue;
    }

    if(board.at(fY).at(x).tileNumber == currentNum)
    {
      // we have found a duplicate number
    }

    board.at(fY).at(x).tileNotes.at(currentNum-1) = false;
  }
}

void sudokuBoard::rowNotes(int y,int x)
{
  int currentNum(board.at(y).at(x).tileNumber);
  if(!board.at(y).at(x).isTaken()) // if a number isn't set, then there is nothing that needs updating
  {
    continue;
  }

  for(int fX=0;fX < (squareSize * squareSize);++fX)
  {

    if(board.at(y).at(fX).isTaken())
    {
      continue;
    }

    if(board.at(y).at(fX).tileNumber == currentNumber)
    {
      // we have found a duplicate number
    }

    board.at(y).at(fX).tileNotes.at(currentNum-1) = false;
  }
}

void sudokuBoard::squareNotes(int y,int x)
{
  if(!board.at(y).at(x).isTaken())
  {
    return;
  }

  int outerY((y / squareSize) * squareSize);
  int outerX((x / squareSize) * squareSize);

  int inpNum(board.at(y).at(x).tileNumber);


  int innerY;
  int innerX;

  for(innerY = 0; innerY < squareSize; ++innerY)
  {
    for(innerX = 0; innerX < squareSize; ++innerX)
    {
      if(board.at(innerY + outerY).at(innerX + outerX).isTaken())
      {
        continue;
      }
      
      if(board.at(innerY + outerY).at(innerX + outerX).tileNumber == inpNum)
      {
        // duplicate number
      }

      board.at(innerY + outerY).at(innerX + outerX).removeNote(inpNum);
    }
  }
}

bool sudokuBoard::boardContainsNoteCount(int wantedNoteCount)
{
  for(int i=0;i<(squareSize*squareSize);++i)
  {
    for(int x=0;x<(squareSize*squareSize);++x)
    {
      if(!board.at(y).at(x).isTaken())
      {
        if(board.at(y).at(x).getNoteCount() == wantedNoteCount)
        {
          return true;
        }
      }
    }
  }
  return false;
}

vector<int> sudokuBoard::findLowestNoteCount(int wantedNum)
{
  vector<int> coords{-1,-1};
  int lowestCount(squareSize*squareSize); 
  for(int y=0;y<(squareSize*squareSize);++y)
  {
    for(int x=0;x<(squareSize*squareSize);++x)
    {
      if(!board.at(y).at(x).isTaken())
      {
        if(board.at(y).at(x).getNoteCount() < lowestCount)
        {
          coords.at(0) = y;
          coords.at(1) = x;
          lowestCount = board.at(y).at(x).getNoteCount();
        }
      }
    }
  }
  return coords;
}

void sudokuBoard::placeFrontNumber(int y,int x,int number)
{
  // can't add 0 and checking to see if the note is already crossed off
  if(number == 0 || !board.at(y).at(x).canBeHere(number))
  {
    return;
  }
  
  board.at(y).at(x).placeNum(number);
  rowNotes(y,x);
  columnNotes(y,x);
  squareNotes(y,x);
}

bool sudokuBoard::isValidBoard()
{

}

bool sudokuBoard::isBoardSolved()
{

}
