/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 3 - Game of Life
 * This is the implementation .cpp file for the Configuration class which creates the configuration of the initial world
*/
#include "Configuration.h"

Configuration::Configuration() { //default constructor
  rows = 0;
  columns = 0;
}

Configuration::~Configuration() { //default destructor

}

unsigned short Configuration::getRows() { //returns rows
  return rows;
}

unsigned short Configuration::getColumns() { //returns columns
  return columns;
}

char** Configuration::randomConfiguration() { //creates a random configuration with dimensions and population density given by user input
  double populationDensity;
  unsigned short initialPopulation;
  cout << "How many rows should the world have?" << endl;
  cin >> rows;
  cout << "How many columns should the world have?" << endl;
  cin >> columns;
  char** world = new char*[rows];
  for (int i = 0; i < rows; ++i) {
    world[i] = new char[columns];
  }
  cout << "Enter a decimal greater than 0 and less than or equal to 1 for the initial population density of the world" << endl;
  cin >> populationDensity; 
  initialPopulation = (rows * columns) * populationDensity; //rounded down to nearest int
  for (int r = 0; r < rows; ++r) { //fills world with correct num of X's and -'s, will randomly shuffle order later
    for (int c = 0; c < columns; ++c) {
      world[r][c] = '-';
      if (initialPopulation > 0) {
        world[r][c] = 'X';
        --initialPopulation;
      }
    }
  }
  for (int r = 0; r < rows; ++r) { //randomizes order of elements in 2d array world
    for (int c = 0; c < columns; ++c) {
      unsigned short r1 = rand() % rows; //random num from 0 ro rows-1
      unsigned short c1 = rand() % columns; //random number from 0 to columns-1
      char temp = world[r][c];
      world[r][c] = world[r1][c1];
      world[r1][c1] = temp;
    }
  }
  return world;
}

char** Configuration::mapFile() { //creates a configuration using a map file inputted by the user
  string fileName;
  fstream fileStream;
  char character;
  unsigned short r = 0;
  unsigned short c = 0;
  char** world;
  cout << "Enter of the file to read the map from:" << endl;
  cin >> fileName;
  fileStream.open(fileName, ios::in); // opens inputFile in read mode
  if (fileStream.fail()) { // checks if file was opened incorrectly
		cout << "Input file not opened!" << endl;
	} else {
    cout << "Input file opened successfully!" << endl;
    fileStream >> rows;
    fileStream >> columns;
    world = new char*[rows];
    for (int i = 0; i < rows; ++i) {
      world[i] = new char[columns];
    }
    while (r < rows && c < columns) { // loops through entire file, character by character, until the end is reached
      fileStream >> character;
      if (toupper(character) == 'X') { //if an x or X is read from the file, add it to the 2d array world
        world[r][c] = 'X';
      } else { //else add a '-'
        world[r][c] = '-';
      }
      c++;
      if (c == columns) { //if at last column, go back to first column and next row
        c = 0;
        r++;
      }
		}
    fileStream.close();
    fileStream.clear();
    return world;
  }
}
