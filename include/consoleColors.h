#ifndef CONSOLECOLORS_H
#define CONSOLECOLORS_H

#include <vector>
#include <iostream>
using std::string;
using std::vector;
struct consColors
{
  // the F stands for front color
  string redF = "\033[31m";
  string greenF = "\033[32m";
  string yellowF = "\033[33m";
  string blueF = "\033[34m";
  string magentaF = "\033[35m";
  string cyanF = "\033[36m";
  string whiteF = "\033[37m";

  // the B stands for background color
  string redB = "\033[41m";
  string greenB = "\033[42m";
  string yellowB = "\033[43m";
  string blueB = "\033[44m";
  string magentaB = "\033[45m";
  string cyanB = "\033[46m";
  string whiteB = "\033[47m";

  // color options
  string resetColor = "\033[0m";
  string boldF = "\033[1m";
  string underLine = "\033[4m";
  string inverseColors = "\033[7m";

  int rainbowLength = 6;
  vector<string> rainbowF{redF,yellowF,greenF,cyanF,blueF,magentaF};
  // the B in rainbowFB stands for bold instead of background in this case
  vector<string> rainbowFB{redF + boldF,yellowF + boldF,greenF + boldF,cyanF + boldF,blueF + boldF,magentaF + boldF};
  vector<string> rainbowB{redB,yellowB,greenB,cyanB,blueB,magentaB};
};

#endif
