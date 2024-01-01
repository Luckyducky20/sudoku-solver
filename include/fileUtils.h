#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> getSpecificFileNames(std::filesystem::path);
vector<string> getFileNames();
vector<string> getFileContents();

void generateBoardBatch();

#endif
