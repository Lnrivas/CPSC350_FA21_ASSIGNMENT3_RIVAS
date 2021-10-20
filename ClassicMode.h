/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 3 - Game of Life
 * This is the header .h file for the ClassicMode class which is used to play classic mode and print or output to a file the generations along with tell if the wolrd is stable or empty
*/
#include <iostream>
#include <fstream>

using namespace std;

class ClassicMode {
public:
  ClassicMode(); //default constructor
  ~ClassicMode(); //default desctructor
  void printWorld(char** world, unsigned short rows, unsigned short columns); //prints the world to the terminal
  void outputToFile(char** world, unsigned short rows, unsigned short columns, string outputFile, unsigned int generationNumber); // appends the world to a given file
  unsigned short countNeighbors(char** world, unsigned short rows, unsigned short columns, unsigned short rowOfElement, unsigned short columnOfElement); //counts the neighbors of an element
  bool isEmpty(char** world, unsigned short rows, unsigned short columns); //checks if a world is empty
  bool getIsStable(); //checks if a world is stable
  void playClassicMode(char** world, unsigned short rows, unsigned short columns, unsigned short briefPause, string outputFile, unsigned int generationNumber); // plays the game of life in classic mode
private:
  bool isStable; // variable to tell if world is stable
};
