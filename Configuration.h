/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 3 - Game of Life
 * This is the header .h file for the Configuration class
*/
#include <iostream>
#include <fstream>

using namespace std;

class Configuration {
public:
  Configuration();
  ~Configuration();
  char** randomConfiguration();
  char** mapFile();
  unsigned short getRows();
  unsigned short getColumns();
private:
  unsigned short rows;
  unsigned short columns;
};
