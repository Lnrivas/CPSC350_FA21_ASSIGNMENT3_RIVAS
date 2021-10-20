/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 3 - Game of Life
 * This is the header .h file for the MirrorMode class
*/
#include <iostream>
#include <fstream>

using namespace std;

class MirrorMode {
public:
  MirrorMode();
  ~MirrorMode();
  void printWorld(char** world, unsigned short rows, unsigned short columns);
  void outputToFile(char** world, unsigned short rows, unsigned short columns, string outputFile, unsigned int generationNumber);
  unsigned short countNeighbors(char** world, unsigned short rows, unsigned short columns, unsigned short rowOfElement, unsigned short columnOfElement);
  bool isEmpty(char** world, unsigned short rows, unsigned short columns);
  bool getIsStable();
  void playMirrorMode(char** world, unsigned short rows, unsigned short columns, unsigned short briefPause, string outputFile, unsigned int generationNumber);
private:
  bool isStable;
};
