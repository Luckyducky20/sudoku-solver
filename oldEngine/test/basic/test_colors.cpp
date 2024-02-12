#include <iostream>
#include "../../include/consoleColors.h"

using namespace std;

int main()
{
  consColors colorPal;
  cout << colorPal.redF << "red" << colorPal.resetColor << "\n";
  cout << colorPal.greenF << "green" << colorPal.resetColor << "\n";
  cout << colorPal.yellowF << "yellow" << colorPal.resetColor << "\n";
  cout << colorPal.blueF << "blue" << colorPal.resetColor << "\n";
  cout << colorPal.magentaF << "magenta" << colorPal.resetColor << "\n";
  cout << colorPal.cyanF << "cyan" << colorPal.resetColor << "\n";
  cout << colorPal.whiteF << "white" << colorPal.resetColor << "\n";
  
  cout << colorPal.redB << "red" << colorPal.resetColor << "\n";
  cout << colorPal.greenB << "green" << colorPal.resetColor << "\n";
  cout << colorPal.yellowB << "yellow" << colorPal.resetColor << "\n";
  cout << colorPal.blueB << "blue" << colorPal.resetColor << "\n";
  cout << colorPal.magentaB << "magenta" << colorPal.resetColor << "\n";
  cout << colorPal.cyanB << "cyan" << colorPal.resetColor << "\n";
  cout << colorPal.whiteB << "white" << colorPal.resetColor << "\n";

  cout << colorPal.boldF << "bold" << colorPal.resetColor << "\n";
  cout << colorPal.underLine << "underline" << colorPal.resetColor << "\n";
  cout << colorPal.yellowF << colorPal.redB << "before" << colorPal.inverseColors << "inversed" << colorPal.resetColor << "\n";

  return 0;
}
