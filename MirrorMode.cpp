/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 3 - Game of Life
 * This is the implementation .cpp file for the MirrorMode class.
*/
#include "MirrorMode.h"

MirrorMode::MirrorMode() {
  isStable = true;
}

MirrorMode::~MirrorMode() {

}

void MirrorMode::printWorld(char** world, unsigned short rows, unsigned short columns) {
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < columns; ++c) {
      cout << world[r][c];
    }
    cout << endl;
  }
}

void MirrorMode::outputToFile(char** world, unsigned short rows, unsigned short columns, string outputFile, unsigned int generationNumber) {
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

unsigned short MirrorMode::countNeighbors(char** world, unsigned short rows, unsigned short columns, unsigned short rowOfElement, unsigned short columnOfElement) { //this method differs per mode
  unsigned short count = 0;
  if (rowOfElement != 0 && columnOfElement != 0 && world[rowOfElement-1][columnOfElement-1] == 'X') { //if not top or left, top left is top left
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement != 0 && world[rowOfElement][columnOfElement-1] == 'X') { //if top but not left corner, top left is left
    count++;
  }
  else if (columnOfElement == 0 && rowOfElement != 0 && world[rowOfElement-1][columnOfElement] == 'X') { //if left but not top corner, top left is top
    count++;
  }

  if (rowOfElement != 0 && world[rowOfElement-1][columnOfElement] == 'X') { //if not top, top middle is top middle
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement != 0 && columnOfElement != columns-1 && world[rowOfElement][columnOfElement] == 'X') { //if top but not a corner, top middle is itself
    count++;
  }

  if (rowOfElement != 0 && columnOfElement != columns-1 && world[rowOfElement-1][columnOfElement+1] == 'X') { //check for top right element
    count++;
  }
  else if (rowOfElement == 0 && columnOfElement != columns-1 && world[rowOfElement][columnOfElement+1] == 'X') { //if top but not right corner, top right is right
    count++;
  }
  else if (columnOfElement == columns-1 && rowOfElement != 0 && world[rowOfElement-1][columnOfElement] == 'X') { //if right but not top corner, top right is top
    count++;
  }

  if (columnOfElement != 0 && world[rowOfElement][columnOfElement-1] == 'X') { //check for middle left element
    count++;
  }
  else if (columnOfElement == 0 && rowOfElement != 0 && rowOfElement != rows-1 && world[rowOfElement][columnOfElement] == 'X') { //if left but not a corner, middle left is itself
    count++;
  }

  if (columnOfElement != columns-1 && world[rowOfElement][columnOfElement+1] == 'X') { //check for middle right element
    count++;
  }
  else if (columnOfElement == columns-1 && rowOfElement != 0 && rowOfElement != rows-1 && world[rowOfElement][columnOfElement] == 'X') { //if right but not a corner, middle right is itself
    count++;
  }

  if (rowOfElement != rows-1 && columnOfElement != 0 && world[rowOfElement+1][columnOfElement-1] == 'X') { //check for bottom left element
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement != 0 && world[rowOfElement][columnOfElement-1] == 'X') { //if bottom but not left corner, bottom left is left
    count++;
  }
  else if (columnOfElement == 0 && rowOfElement != rows-1 && world[rowOfElement+1][columnOfElement] == 'X') { //if left but not bottom corner, bottom left is bottom
    count++;
  }

  if (rowOfElement != rows-1 && world[rowOfElement+1][columnOfElement] == 'X') { //check for bottom middle element
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement != 0 && columnOfElement != columns-1 && world[rowOfElement][columnOfElement] == 'X') { //if bottom but not a corner, bottom middle is itself
    count++;
  }

  if (rowOfElement != rows-1 && columnOfElement != columns-1 && world[rowOfElement+1][columnOfElement+1] == 'X') { //check for bottom right element
    count++;
  }
  else if (rowOfElement == rows-1 && columnOfElement != columns-1 && world[rowOfElement][columnOfElement+1] == 'X') { //if bottom but not right corner, bottom right is right
    count++;
  }
  else if (columnOfElement == columns-1 && rowOfElement != rows-1 && world[rowOfElement+1][columnOfElement] == 'X') { //if right but not bottom corner, bottom right is bottom
    count++;
  }

  if (rowOfElement == 0 && columnOfElement == 0 && world[rowOfElement][columnOfElement] == 'X') { //if top left corner, add 3 to count
    count += 3;
  }
  else if (rowOfElement == 0 && columnOfElement == columns-1 && world[rowOfElement][columnOfElement] == 'X') { //if top right corner, add 3 to count
    count += 3;
  }
  else if (rowOfElement == rows-1 && columnOfElement == 0 && world[rowOfElement][columnOfElement] == 'X') { //if bottom left corner, add 3 to count
    count += 3;
  }
  else if (rowOfElement == rows-1 && columnOfElement == columns-1 && world[rowOfElement][columnOfElement] == 'X') { //if bottom right corner, add 3 to count
    count += 3;
  }

  // if (rowOfElement != 0 && rowOfElement != rows-1 && columnOfElement != 0 && columnOfElement != columns-1) { //if not on any edge, count all 8 neighbors normally
  //   if (world[rowOfElement-1][columnOfElement-1] == 'X') { //top left
  //     count++;
  //   }
  //   if (world[rowOfElement-1][columnOfElement] == 'X') { //top middle
  //     count++;
  //   }
  //   if (world[rowOfElement-1][columnOfElement+1] == 'X') { //top right
  //     count++;
  //   }
  //   if (world[rowOfElement][columnOfElement-1] == 'X') { //middle left
  //     count++;
  //   }
  //   if (world[rowOfElement][columnOfElement+1] == 'X') { //middle right
  //     count++;
  //   }
  //   if (world[rowOfElement+1][columnOfElement-1] == 'X') { //bottom left
  //     count++;
  //   }
  //   if (world[rowOfElement+1][columnOfElement] == 'X') { //bottom middle
  //     count++;
  //   }
  //   if (world[rowOfElement+1][columnOfElement+1] == 'X') { //bottom right
  //     count++;
  //   }
  // }
  //cout << "row: " << rowOfElement << " column: " << columnOfElement << " count: " << count  << endl;
  return count;
}

bool MirrorMode::isEmpty(char** world, unsigned short rows, unsigned short columns) {
  for (int r = 0; r < rows; ++r) { //copies nextWorld into world
    for (int c = 0; c < columns; ++c) {
      if (world[r][c] == 'X') {
        return false; //not empty if it ever finds an X in world
      }
    }
  }
  return true; //if this is reached, no X was found in world aka it is empty
}

bool MirrorMode::getIsStable() {
  return isStable;
}

//follow rules and use world to make nextWorld (next generation) then copy into world and print world along with generaton num
void MirrorMode::playMirrorMode(char** world, unsigned short rows, unsigned short columns, unsigned short briefPause, string outputFile, unsigned int generationNumber) {
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
