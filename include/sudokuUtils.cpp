#include "sudokuUtils.h"
#include "boardNumber.h"
#include "consoleColors.h"

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::to_string;
using std::string;
using std::cout;
using std::stoi;

vector<string> getStringBoard(string boardString)
{
  vector<string> newBoard;
  string currentLine = "";

  for(int i=0;i<9;++i)
  {
    if(i!=0 && i%3 == 0)
    {
      newBoard.push_back("---+---+---");
    }
    for(int j=0;j<9;++j)
    {
      if(j!=0 && j % 3==0)
      {
        currentLine += "|";
      }
      currentLine += boardString.at((i*9)+j);
    }
    newBoard.push_back(currentLine);
    currentLine = "";
  }
  return newBoard;
}

vector<string> getStringBoardVec(vector<vector<boardNumber>> boardVector)
{
  vector<string> newBoard;
  string currentLine = "";

  for(int i=0;i<9;++i)
  {
    if(i!=0 && i%3 == 0)
    {
      newBoard.push_back("---+---+---");
    }
    for(int j=0;j<9;++j)
    {
      if(j!=0 && j % 3==0)
      {
        currentLine += "|";
      }
      if(boardVector.at(i).at(j).number == 0)
      {
        currentLine += ".";
      }else{
        currentLine += to_string(boardVector.at(i).at(j).number);
      }
    }
    newBoard.push_back(currentLine);
    currentLine = "";
  }
  return newBoard;
}

string getLayerSlice(vector<vector<boardNumber>> inputtedBoard,int sliceNumber)
{
  return getStringBoardVec(inputtedBoard).at(sliceNumber);
}

void printBoard(vector<string> inputtedBoard)
{
  for(int i=0;i<int(inputtedBoard.size());++i)
  {
    cout << inputtedBoard.at(i) << "\n";
  }
}

//prints a cyan board by default
void printColoredBoard(vector<string> inputtedBoard)
{
  consColors colorPal;
  printCCBoard(inputtedBoard,colorPal.cyanF);
}

// print custom color board
void printCCBoard(vector<string> inputtedBoard,string colorCode)
{
  vector<string> coloredBoard = getCCBoard(inputtedBoard,colorCode);
  for(int i=0;i<11;++i)
  {
    cout << coloredBoard.at(i) << "\n";
  }
}


vector<string> getCCBoard(vector<string> inputtedBoard,string colorCode)
{
  
  consColors colorPal; 
  vector<string> boardSlices;

  string currentSlice;
  for(int i=0;i<11;++i)
  {
    if(i != 0 && (i+1) % 4 == 0)
    {
      currentSlice = colorPal.boldF;
      currentSlice += colorCode;
      currentSlice += inputtedBoard.at(i);
      currentSlice += colorPal.resetColor;
      boardSlices.push_back(currentSlice);
    }else{
      currentSlice = inputtedBoard.at(i).substr(0,3);
      currentSlice += colorPal.boldF;
      currentSlice += colorCode;
      currentSlice += "|";
      currentSlice += colorPal.resetColor;
      currentSlice += inputtedBoard.at(i).substr(4,3);
      currentSlice += colorPal.boldF;
      currentSlice += colorCode;
      currentSlice += "|";
      currentSlice += colorPal.resetColor;
      currentSlice += inputtedBoard.at(i).substr(8,3);
      boardSlices.push_back(currentSlice);
    }
  }

  return boardSlices;
}

string getLayerSliceC(vector<vector<boardNumber>> inputtedBoard,int sliceNumber, string colorCode)
{
  return getCCBoard(getStringBoardVec(inputtedBoard),colorCode).at(sliceNumber);
}

vector<string> highlightedBoard(vector<vector<boardNumber>> inputtedBoard,string boardColor,string highlightColor)
{
  vector<string> sliceHolder;
  consColors colorPal;
  string currentLine;

  
  currentLine = highlightColor;
  currentLine += "               ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  
  currentLine = highlightColor;
  currentLine += " ";
  currentLine += colorPal.resetColor;
  currentLine += "             ";
  currentLine += highlightColor;
  currentLine += " ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);

  for(int i=0;i<11;++i)
  {
    currentLine = highlightColor;
    currentLine += " ";
    currentLine += colorPal.resetColor;
    currentLine += " ";
    currentLine += getLayerSliceC(inputtedBoard,i,boardColor);
    currentLine += " ";
    currentLine += highlightColor;
    currentLine += " ";
    currentLine += colorPal.resetColor;
    sliceHolder.push_back(currentLine);
  }
  
  currentLine = highlightColor;
  currentLine += " ";
  currentLine += colorPal.resetColor;
  currentLine += "             ";
  currentLine += highlightColor;
  currentLine += " ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);

  currentLine = highlightColor;
  currentLine += "               ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  return sliceHolder;
}


vector<string> rainbowBoard(vector<vector<boardNumber>> inputtedBoard)
{
  vector<string> sliceHolder;
  string currentLine;

  consColors colorPal;
  
  currentLine = colorPal.rainbowB[0] + "               " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  
  currentLine = colorPal.rainbowB[1] + " " + colorPal.resetColor + "             " + colorPal.rainbowB[1] + " " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);

  int loopRange = 11;
  for(int i=0;i<loopRange;++i)
  {
    currentLine = colorPal.rainbowB[(i+2) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    currentLine += " ";
    currentLine += getLayerSliceC(inputtedBoard,i,colorPal.rainbowF[(i+2) % colorPal.rainbowLength]);
    currentLine += " ";
    currentLine += colorPal.rainbowB[(i+2) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    sliceHolder.push_back(currentLine);
  }
  
  currentLine = colorPal.rainbowB[(loopRange + 2) % colorPal.rainbowLength]; 
  currentLine += " ";
  currentLine += colorPal.resetColor;
  currentLine += "             ";
  currentLine += colorPal.rainbowB[(loopRange + 2) % colorPal.rainbowLength];
  currentLine += " ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  loopRange++;

  currentLine = colorPal.rainbowB[(loopRange + 2) % colorPal.rainbowLength];
  currentLine += "               ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  return sliceHolder;
}


vector<string> rainbowInner(vector<vector<boardNumber>> inputtedBoard)
{
  vector<string> sliceHolder;
  string currentLine;

  consColors colorPal;
  
  currentLine = "               ";
  sliceHolder.push_back(currentLine);
  sliceHolder.push_back(currentLine);

  int loopRange = 11;
  for(int i=0;i<loopRange;++i)
  {
    currentLine = "  ";
    currentLine += getLayerSliceC(inputtedBoard,i,colorPal.rainbowF[i % colorPal.rainbowLength]);
    currentLine += "  ";
    currentLine += colorPal.resetColor;
    sliceHolder.push_back(currentLine);
  }

  currentLine = "               ";
  sliceHolder.push_back(currentLine);
  sliceHolder.push_back(currentLine);
  return sliceHolder;
}


vector<string> rainbowHighlight(vector<vector<boardNumber>> inputtedBoard)
{
  vector<string> sliceHolder;
  string currentLine;

  consColors colorPal;
  
  currentLine = colorPal.rainbowB[0] + "               " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  
  currentLine = colorPal.rainbowB[1] + " " + colorPal.resetColor + "             " + colorPal.rainbowB[1] + " " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);

  int loopRange = 11;
  for(int i=0;i<loopRange;++i)
  {
    currentLine = colorPal.rainbowB[(i+2) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    currentLine += " ";
    currentLine += getLayerSlice(inputtedBoard,i);
    currentLine += " ";
    currentLine += colorPal.rainbowB[(i+2) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    sliceHolder.push_back(currentLine);
  }
  
  currentLine = colorPal.rainbowB[(loopRange + 2) % colorPal.rainbowLength]; 
  currentLine += " ";
  currentLine += colorPal.resetColor;
  currentLine += "             ";
  currentLine += colorPal.rainbowB[(loopRange + 2) % colorPal.rainbowLength];
  currentLine += " ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  loopRange++;

  currentLine = colorPal.rainbowB[(loopRange + 2) % colorPal.rainbowLength];
  currentLine += "               ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  return sliceHolder;
}


vector<string> rainbowBoardSyncIn(vector<vector<boardNumber>> inputtedBoard, int innerColorShift)
{
  vector<string> sliceHolder;
  string currentLine;

  consColors colorPal;
  
  currentLine = colorPal.rainbowB[0] + "               " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  
  currentLine = colorPal.rainbowB[1] + " " + colorPal.resetColor + "             " + colorPal.rainbowB[1] + " " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);

  int loopRange = 11;
  for(int i=0;i<loopRange;++i)
  {
    currentLine = colorPal.rainbowB[(i+2) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    currentLine += " ";
    currentLine += getLayerSliceC(inputtedBoard,i,colorPal.rainbowF[(i+2 + innerColorShift) % colorPal.rainbowLength]);
    currentLine += " ";
    currentLine += colorPal.rainbowB[(i+2) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    sliceHolder.push_back(currentLine);
  }
  
  currentLine = colorPal.rainbowB[(loopRange + 2) % colorPal.rainbowLength]; 
  currentLine += " ";
  currentLine += colorPal.resetColor;
  currentLine += "             ";
  currentLine += colorPal.rainbowB[(loopRange + 2) % colorPal.rainbowLength];
  currentLine += " ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  loopRange++;

  currentLine = colorPal.rainbowB[(loopRange + 2) % colorPal.rainbowLength];
  currentLine += "               ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  return sliceHolder;
}

vector<string> rainbowBoardSyncOut(vector<vector<boardNumber>> inputtedBoard, int outerColorShift)
{
  vector<string> sliceHolder;
  string currentLine;

  consColors colorPal;
  
  currentLine = colorPal.rainbowB[0 + outerColorShift] + "               " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  
  currentLine = colorPal.rainbowB[1 + outerColorShift] + " " + colorPal.resetColor + "             " + colorPal.rainbowB[1 + outerColorShift] + " " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);

  int loopRange = 11;
  for(int i=0;i<loopRange;++i)
  {
    currentLine = colorPal.rainbowB[(i+2 + outerColorShift) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    currentLine += " ";
    currentLine += getLayerSliceC(inputtedBoard,i,colorPal.rainbowF[(i+2) % colorPal.rainbowLength]);
    currentLine += " ";
    currentLine += colorPal.rainbowB[(i+2 + outerColorShift) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    sliceHolder.push_back(currentLine);
  }
  
  currentLine = colorPal.rainbowB[(loopRange + 2 + outerColorShift) % colorPal.rainbowLength]; 
  currentLine += " ";
  currentLine += colorPal.resetColor;
  currentLine += "             ";
  currentLine += colorPal.rainbowB[(loopRange + 2 + outerColorShift) % colorPal.rainbowLength];
  currentLine += " ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  loopRange++;

  currentLine = colorPal.rainbowB[(loopRange + 2 + outerColorShift) % colorPal.rainbowLength];
  currentLine += "               ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  return sliceHolder;
}


vector<string> rainbowBoardSync(vector<vector<boardNumber>> inputtedBoard, int colorShift)
{
  vector<string> sliceHolder;
  string currentLine;

  consColors colorPal;
  
  currentLine = colorPal.rainbowB[(0 + colorShift) % colorPal.rainbowLength] + "               " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  
  currentLine = colorPal.rainbowB[(1 + colorShift) % colorPal.rainbowLength] + " " + colorPal.resetColor + "             " + colorPal.rainbowB[(1 + colorShift) % colorPal.rainbowLength] + " " + colorPal.resetColor;
  sliceHolder.push_back(currentLine);

  int loopRange = 11;
  for(int i=0;i<loopRange;++i)
  {
    currentLine = colorPal.rainbowB[(i+2 + colorShift) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    currentLine += " ";
    currentLine += getLayerSliceC(inputtedBoard,i,colorPal.rainbowF[(i+2 + colorShift) % colorPal.rainbowLength]);
    currentLine += " ";
    currentLine += colorPal.rainbowB[(i+2 + colorShift) % colorPal.rainbowLength];
    currentLine += " ";
    currentLine += colorPal.resetColor;
    sliceHolder.push_back(currentLine);
  }
  
  currentLine = colorPal.rainbowB[(loopRange + 2 + colorShift) % colorPal.rainbowLength]; 
  currentLine += " ";
  currentLine += colorPal.resetColor;
  currentLine += "             ";
  currentLine += colorPal.rainbowB[(loopRange + 2 + colorShift) % colorPal.rainbowLength];
  currentLine += " ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  loopRange++;

  currentLine = colorPal.rainbowB[(loopRange + 2 + colorShift) % colorPal.rainbowLength];
  currentLine += "               ";
  currentLine += colorPal.resetColor;
  sliceHolder.push_back(currentLine);
  return sliceHolder;
}


vector<vector<boardNumber>> convertBoard(string boardString)
{
  vector<vector<boardNumber>> returningBoard;
  vector<boardNumber> emptyRow;
  boardNumber emptyNumber;
  for(int i=0;i<9;++i)
  {
    returningBoard.push_back(emptyRow);
    for(int j=0;j<9;++j)
    {
      
      char charNum = boardString.at((i*9)+j);
      boardNumber newNumber = boardNumber(int(charNum - '0'));
      returningBoard.at(i).push_back(newNumber);
    }
  }

  return returningBoard;
}

vector<vector<vector<boardNumber>>> convertBoards(string boardStrings)
{
	vector<vector<vector<boardNumber>>> returningBoards;
	vector<vector<boardNumber>> currentBoard;
	for(unsigned int i=0;i< boardStrings.length() /81;i++)
	{
		currentBoard = convertBoard(boardStrings.substr(i*81,81));
		returningBoards.push_back(currentBoard);
	}	

	return returningBoards;
}

