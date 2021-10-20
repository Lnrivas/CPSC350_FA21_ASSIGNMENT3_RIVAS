/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 3 - Game of Life
 * This is the implementation .cpp file for the ClassicMode class which is used to play classic mode and print or output to a file the generations along with tell if the wolrd is stable or empty
*/
#include "ClassicMode.h"

ClassicMode::ClassicMode() { // default constructor
  isStable = true;
}

ClassicMode::~ClassicMode() { // default destructor

}

void ClassicMode::printWorld(char** world, unsigned short rows, unsigned short columns) { //prints the world to the terminal
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < columns; ++c) {
      cout << world[r][c];
    }
    cout << endl;
  }
}

void ClassicMode::outputToFile(char** world, unsigned short rows, unsigned short columns, string outputFile, unsigned int generationNumber) { // appends the world to a given file
  fstream fileStream;
  fileStream.open(outputFile, ios::app); // opens outputFile in append mode
  if (fileStream.fail()) { // checks if file was opened incorrectly
    cout << "Output file not opened!" << endl;
  }
  else { // if file was opened correctly
    fileStream << generationNumber << endl;
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < columns; ++c) {
        fileStream << world[r][c];
      }
      fileStream << endl;
    }
  }
  fileStream.close();
  fileStream.clear();
}

unsigned short ClassicMode::countNeighbors(char** world, unsigned short rows, unsigned short columns, unsigned short rowOfElement, unsigned short columnOfElement) { //counts the neighbors of an element
  unsigned short count = 0;
  if (rowOfElement != 0 && columnOfElement != 0 && world[rowOfElement-1][columnOfElement-1] == 'X') { //check for top left element
    count++;
  }
  if (rowOfElement != 0 && world[rowOfElement-1][columnOfElement] == 'X') { //check for top middle element
    count++;
  }
  if (rowOfElement != 0 && columnOfElement != columns-1 && world[rowOfElement-1][columnOfElement+1] == 'X') { //check for top right element
    count++;
  }
  if (columnOfElement != 0 && world[rowOfElement][columnOfElement-1] == 'X') { //check for middle left element
    count++;
  }
  if (columnOfElement != columns-1 && world[rowOfElement][columnOfElement+1] == 'X') { //check for middle right element
    count++;
  }
  if (rowOfElement != rows-1 && columnOfElement != 0 && world[rowOfElement+1][columnOfElement-1] == 'X') { //check for bottom left element
    count++;
  }
  if (rowOfElement != rows-1 && world[rowOfElement+1][columnOfElement] == 'X') { //check for bottom middle element
    count++;
  }
  if (rowOfElement != rows-1 && columnOfElement != columns-1 && world[rowOfElement+1][columnOfElement+1] == 'X') { //check for bottom right element
    count++;
  }
  return count;
}

bool ClassicMode::isEmpty(char** world, unsigned short rows, unsigned short columns) { //checks if a world is empty
  for (int r = 0; r < rows; ++r) { //copies nextWorld into world
    for (int c = 0; c < columns; ++c) {
      if (world[r][c] == 'X') {
        return false; //not empty if it ever finds an X in world
      }
    }
  }
  return true; //if this is reached, no X was found in world aka it is empty
}

bool ClassicMode::getIsStable() { //checks if a world is stable
  return isStable;
}

//follow rules and use world to make nextWorld (next generation) then copy into world and print world along with generaton num
void ClassicMode::playClassicMode(char** world, unsigned short rows, unsigned short columns, unsigned short briefPause, string outputFile, unsigned int generationNumber) { // plays the game of life in classic mode
  isStable = true;
  char** nextWorld = new char*[rows]; //creates empty char** nextWorld
  for (int i = 0; i < rows; ++i) {
    nextWorld[i] = new char[columns];
  }
  for (int r = 0; r < rows; ++r) { //use rules to make nextWorld
    for (int c = 0; c < columns; ++c) {
      if (countNeighbors(world, rows, columns, r, c) <= 1) { //rule 1: if 1 or 0 neighbors, no cell there in nextWorld
        nextWorld[r][c] = '-';
      }
      if (countNeighbors(world, rows, columns, r, c) == 2) { //rule 2: if 2 neighbors, cell remains stable in nextWorld
        nextWorld[r][c] = world[r][c];
      }
      if (countNeighbors(world, rows, columns, r, c) == 3) { //rule 3: if 3 neighbors, cell will exist in nextWorld wether it was there before or not
        nextWorld[r][c] = 'X';
      }
      if (countNeighbors(world, rows, columns, r, c) >= 4) { //rule 4: if 4 or more neighbors, no cell there in nextWorld due to overcrowding
        nextWorld[r][c] = '-';
      }
    }
  }
  for (int r = 0; r < rows; ++r) { //checks for stability, if there is any difference between world and nextWorld, it is not stable. Otherwise it is stable.
    for (int c = 0; c < columns; ++c) {
      if (world[r][c] != nextWorld[r][c]) {
        isStable = false;
      }
    }
  }
  for (int r = 0; r < rows; ++r) { //copies nextWorld into world
    for (int c = 0; c < columns; ++c) {
      world[r][c] = nextWorld[r][c];
    }
  }
  if (briefPause == 3) {
    outputToFile(world, rows, columns, outputFile, generationNumber);
  } else {
    cout << generationNumber << endl;
    printWorld(world, rows, columns);
  }
}
