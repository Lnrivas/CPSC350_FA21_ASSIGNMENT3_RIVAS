/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 3 - Game of Life
 * This is the implementation .cpp file for the DoughnutMode class.
*/
#include "DoughnutMode.h"

DoughnutMode::DoughnutMode() {
  isStable = true;
}

DoughnutMode::~DoughnutMode() {

}

void DoughnutMode::printWorld(char** world, unsigned short rows, unsigned short columns) {
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < columns; ++c) {
      cout << world[r][c];
    }
    cout << endl;
  }
}

void DoughnutMode::outputToFile(char** world, unsigned short rows, unsigned short columns, string outputFile, unsigned int generationNumber) {
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

unsigned short DoughnutMode::countNeighbors(char** world, unsigned short rows, unsigned short columns, unsigned short rowOfElement, unsigned short columnOfElement) { //this method differs per mode
  unsigned short count = 0;
  if (rowOfElement != 0 && columnOfElement != 0 && world[rowOfElement-1][columnOfElement-1] == 'X') { //check for top left element
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement == 0 && world[rows-1][columns-1] == 'X') { //when element is in topleft corner, top left element is bottom right corner
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement == columns-1 && world[rows-1][columns-2] == 'X') { //when element is in topright corner, top left element is next to bottom right corner
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement == 0 && world[rows-2][columns-1] == 'X') { //when element is in bottomleft corner, top left element is above bottom right right corner
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement != 0 && world[rows-1][columnOfElement-1] == 'X') { //when element is in top row but not left corner, top left is bottom row left element
    count++;
  }
  else if (columnOfElement == 0 && rowOfElement != 0 && world[rowOfElement-1][columns-1] == 'X') { //when element is in left column but not top corner, top left is right column top element
    count++;
  }

  if (rowOfElement != 0 && world[rowOfElement-1][columnOfElement] == 'X') { //check for top middle element
    count++;
  }
  else if (rowOfElement == 0 && world[rows-1][columnOfElement] == 'X') { // if element is at top, check bottom row for "top neighbor"
    count++;
  }

  if (rowOfElement != 0 && columnOfElement != columns-1 && world[rowOfElement-1][columnOfElement+1] == 'X') { //check for top right element
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement == 0 && world[rows-1][1] == 'X') { //when element is in topleft corner, top right element is next to bottom left corner
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement == columns-1 && world[rows-2][0] == 'X') { //when element is in bottomright corner, top right element is above bottom left corner
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement == columns-1 && world[rows-1][0] == 'X') { //when element is in topright corner, top right element is bottom left corner
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement != columns-1 && world[rows-1][columnOfElement+1] == 'X') { //when element is in top row but not right corner, top right is bottom row right element
    count++;
  }
  else if (columnOfElement == columns-1 && rowOfElement != 0 && world[rowOfElement-1][0] == 'X') { //when element is in right column but not top corner, top right is left column top element
    count++;
  }

  if (columnOfElement != 0 && world[rowOfElement][columnOfElement-1] == 'X') { //check for middle left element
    count++;
  }
  else if (columnOfElement == 0 && world[rowOfElement][columns-1] == 'X') { // if element is at left, check right column for "left neighbor"
    count++;
  }

  if (columnOfElement != columns-1 && world[rowOfElement][columnOfElement+1] == 'X') { //check for middle right element
    count++;
  }
  else if (columnOfElement == columns-1 && world[rowOfElement][0] == 'X') { // if element is at right, check left column for "right neighbor"
    count++;
  }

  if (rowOfElement != rows-1 && columnOfElement != 0 && world[rowOfElement+1][columnOfElement-1] == 'X') { //check for bottom left element
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement == 0 && world[1][columns-1] == 'X') { //when element is in topleft corner, bottom left element is below top right corner
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement == 0 && world[0][columns-1] == 'X') { //when element is in bottomleft corner, bottom left element is top right corner
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement == columns-1 && world[0][columns-2] == 'X') { //when element is in bottomright corner, bottom left element is next to top right corner
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement != 0 && world[0][columnOfElement-1] == 'X') { //when element is in bottom row but not left corner, bottom left is top row left element
    count++;
  }
  else if (columnOfElement == 0 && rowOfElement != rows-1 && world[rowOfElement+1][columns-1] == 'X') { //when element is in left column but not bottom corner, bottom left is right column bottom element
    count++;
  }

  if (rowOfElement != rows-1 && world[rowOfElement+1][columnOfElement] == 'X') { //check for bottom middle element
    count++;
  }
  else if (rowOfElement == rows-1 && world[0][columnOfElement] == 'X') { // if element is at bottom, check top row for "bottom neighbor"
    count++;
  }

  if (rowOfElement != rows-1 && columnOfElement != columns-1 && world[rowOfElement+1][columnOfElement+1] == 'X') { //check for bottom right element
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement == columns-1 && world[1][0] == 'X') { //when element is in topright corner, bottom right element is below top left corner
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement == 0 && world[0][1] == 'X') { //when element is in bottomleft corner, bottom right element is next to top left corner
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement == columns-1 && world[0][0] == 'X') { //when element is in bottomright corner, bottom right element is top left corner
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement != columns-1 && world[0][columnOfElement+1] == 'X') { //when element is in bottom row but not right corner, bottom right is top row right element
    count++;
  }
  else if (columnOfElement == columns-1 && rowOfElement != rows-1 && world[rowOfElement+1][0] == 'X') { //when element is in right column but not bottom corner, bottom right is left column bottom element
    count++;
  }
  return count;
}

bool DoughnutMode::isEmpty(char** world, unsigned short rows, unsigned short columns) {
  for (int r = 0; r < rows; ++r) { //copies nextWorld into world
    for (int c = 0; c < columns; ++c) {
      if (world[r][c] == 'X') {
        return false; //not empty if it ever finds an X in world
      }
    }
  }
  return true; //if this is reached, no X was found in world aka it is empty
}

bool DoughnutMode::getIsStable() {
  return isStable;
}

//follow rules and use world to make nextWorld (next generation) then copy into world and print world along with generaton num
void DoughnutMode::playDoughnutMode(char** world, unsigned short rows, unsigned short columns, unsigned short briefPause, string outputFile, unsigned int generationNumber) {
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
