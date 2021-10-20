/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 3 - Game of Life
 * This is the header .h file for the Configuration class which creates the configuration of the initial world
*/
#include <iostream>
#include <fstream>

using namespace std;

class Configuration {
public:
  Configuration(); //default constructor
  ~Configuration(); //default destructor
  char** randomConfiguration(); //creates a random configuration with dimensions and population density given by user input
  char** mapFile(); //creates a configuration using a map file inputted by the user
  unsigned short getRows(); //returns rows
  unsigned short getColumns(); //returns columns
private:
  unsigned short rows; // number of rows in world
  unsigned short columns; // number of columns in world
};
