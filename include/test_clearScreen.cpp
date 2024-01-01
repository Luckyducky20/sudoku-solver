#include <iostream>

using std::cout;

int main()
{
  cout << "This is some output! \n";
  getchar();
  //system("cls");
  cout << "\033[2J";
  cout << "\033[H";
  cout << "The screen has been cleared!\n";






  return 0;
}
