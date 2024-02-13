#include <iostream>
#include <vector>
#include "sudokuTile.h"

using namespace std;

int main()
{
  sudokuTile testTile;
  sudokuTile testTile2(3,5);
  cout << "--------------------------------\n";
  cout << "Tile Test: \n\n";

  cout << "testTile isTake: " << testTile.isTaken() << "\n"; 
  cout << "taken value: " << testTile.getTileNum() << "\n";
  cout << "testTile2 isTake: " << testTile2.isTaken() << "\n"; 
  cout << "taken value: " << testTile2.getTileNum() << "\n";
  
  cout << "--------------------------------\n";

  testTile.setNum(4);
  cout << "testTile isTake: " << testTile.isTaken() << "\n"; 
  cout << "taken value: " << testTile.getTileNum() << "\n";
  testTile = sudokuTile();
  cout << "testTile isTake: " << testTile.isTaken() << "\n"; 
  cout << "taken value: " << testTile.getTileNum() << "\n";
  
  cout << "--------------------------------\n";

  cout << "note count: " << testTile.getNoteCount() << "\n";

  testTile.removeNote(1);
  testTile.removeNote(2);
  testTile.removeNote(3);

  cout << "note count: " << testTile.getNoteCount() << "\n";


  vector<int> currentNotes = testTile.getNotes();

  for(int i=0;i<currentNotes.size();++i)
  {
    cout << "[" << i << "]: " << currentNotes[i] << "\n";
  }

  cout << "--------------------------------\n";

  int Size(7);
  cout << "Give me square size: ";
  cin >> Size;
  testTile = sudokuTile(Size);

  for(int y=0;y<Size;++y)
  {
    for(int x=0;x<Size;++x)
    {
      if(testTile.canBeHere((y*Size) + x+1))
      {
        cout << ((y*Size) + x + 1) << "\t";
      }else
      {
        cout << "\t";
      }
    }
    cout << "\n";
  }
  
  cout << "--------------------------------\n";
  
  
  testTile.removeNote((Size/2) + 1);
  testTile.removeNote((Size/4) + 1);
  testTile.removeNote((Size/3) + 1);
  
  
  for(int y=0;y<Size;++y)
  {
    for(int x=0;x<Size;++x)
    {
      if(testTile.canBeHere((y*Size) + x+1))
      {
        cout << "Y\t";
      }else
      {
        cout << "\t";
      }
    }
    cout << "\n";
  }
  


  return 0;
}
