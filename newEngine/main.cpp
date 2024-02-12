#include <iostream>
#include <vector>
#include "sudokuTile.h"

using namespace std;

int main()
{
  sudokuTile testTile;
  sudokuTile testTile2(5);


  cout << "testTile isTake: " << testTile.isTaken() << "\n"; 
  cout << "taken value: " << testTile.getTileNum() << "\n";
  cout << "testTile2 isTake: " << testTile2.isTaken() << "\n"; 
  cout << "taken value: " << testTile2.getTileNum() << "\n";
  



  return 0;
}
