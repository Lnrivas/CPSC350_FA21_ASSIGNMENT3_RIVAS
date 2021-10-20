/*
 * Name: Luis Rivas
 * ID: 2365948
 * email: lrivas@chapman.edu
 * CPSC-350-03
 * Assignment 3 - Game of Life
 * This is the main file, where our main method lives.
*/
#include "Configuration.h"
#include "ClassicMode.h"
#include "DoughnutMode.h"
#include "MirrorMode.h"

#include <chrono>
#include <thread>
using namespace this_thread;     // sleep_for, sleep_until
using namespace chrono_literals; // ns, us, ms, s, h, etc.
using chrono::system_clock;

int main(int argc, char** argv) {
  unsigned short configurationType;
  unsigned short boundaryMode;
  unsigned short briefPause;
  Configuration *conf = new Configuration();
  ClassicMode *classic = new ClassicMode();
  DoughnutMode *doughnut = new DoughnutMode();
  MirrorMode *mirror = new MirrorMode();
  unsigned short rows;
  unsigned short columns;
  string outputFile = "";
  char** world;
  char** prevPrevWorld; //////////////////////////////////////////////////////
  prevPrevWorld = new char*[rows]; //makes prev world
  for (int i = 0; i < rows; ++i) {
    prevPrevWorld[i] = new char[columns];
  }
  unsigned int generationNumber = 0;

  cout << "If you want to start with a random configuration, press 1" << endl;
  cout << "If you want to specify a map file configuration, press 2" << endl;
  cin >> configurationType;
  if (configurationType == 1) {
    world = conf->randomConfiguration();
  } else if (configurationType == 2) {
    world = conf->mapFile();
  } else {
    cout << "Must enter either 1 or 2!!!" << endl;
    return -1;
  }
  rows = conf->getRows();
  columns = conf->getColumns();

  cout << "What kind of boundary mode do you want to use? Press 1 for Classic mode, 2 for Doughnut mode, and 3 for Mirror mode" << endl;
  cin >> boundaryMode;

  cout << "Press 1 for a brief pause between generations, 2 if you want to have to press the \"enter\" key, or 3 to output to a file" << endl;
  cin >> briefPause;

  if (boundaryMode == 1) { //classic mode
    if (briefPause == 1) { //brief pause stuff
      while (generationNumber == 0 || !(classic->isEmpty(world, rows, columns)) && !(classic->getIsStable())){
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          classic->printWorld(world, rows, columns); //prints initial world
          generationNumber++;
        }
        classic->playClassicMode(world, rows, columns, briefPause, outputFile, generationNumber);
        generationNumber++;
        sleep_for(10ns);
        sleep_until(system_clock::now() + 1s);
      }
      cout << "Press enter to exit the program: ";
      cin.get();
      cin.get();
    } else if (briefPause == 2) { // press enter stuff
      cin.get();
      while (generationNumber == 0 || !(classic->isEmpty(world, rows, columns)) && !(classic->getIsStable())){
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          classic->printWorld(world, rows, columns); //prints initial world
          generationNumber++;
        }
        classic->playClassicMode(world, rows, columns, briefPause, outputFile, generationNumber);
        generationNumber++;
        cin.get();
      }
      cout << "Press enter to exit the program: ";
      cin.get();
    } else if (briefPause == 3) { // output to file stuff
      cout << "Write name of file to output to: " << endl;
      cin >> outputFile;
      while (generationNumber == 0 || !(classic->isEmpty(world, rows, columns)) && !(classic->getIsStable())){
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          classic->outputToFile(world, rows, columns, outputFile, generationNumber); //prints initial world
          generationNumber++;
        }
        classic->playClassicMode(world, rows, columns, briefPause, outputFile, generationNumber);
        generationNumber++;
      }
      cout << "Press enter to exit the program: ";
      cin.get();
      cin.get();
    } else {
      cout << "Must enter 1, 2, or 3!!!" << endl;
      return -1;
    }
  } else if (boundaryMode == 2) { //doughnut mode
    if (briefPause == 1) { //brief pause stuff
      while (generationNumber == 0 || !(doughnut->isEmpty(world, rows, columns)) && !(doughnut->getIsStable())){
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          doughnut->printWorld(world, rows, columns); //this has to be here so below if statement prints intial world?
          generationNumber++;
        }
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          doughnut->printWorld(world, rows, columns); //prints initial world
          generationNumber++;
        }
        doughnut->playDoughnutMode(world, rows, columns, briefPause, outputFile, generationNumber);
        generationNumber++;
        sleep_for(10ns);
        sleep_until(system_clock::now() + 1s);
      }
      cout << "Press enter to exit the program: ";
      cin.get();
      cin.get();
    } else if (briefPause == 2) { // press enter stuff
      cin.get();
      while (generationNumber == 0 || !(doughnut->isEmpty(world, rows, columns)) && !(doughnut->getIsStable())){
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          doughnut->printWorld(world, rows, columns); //prints initial world
          generationNumber++;
        }
        doughnut->playDoughnutMode(world, rows, columns, briefPause, outputFile, generationNumber);
        generationNumber++;
        cin.get();
      }
      cout << "Press enter to exit the program: ";
      cin.get();
    } else if (briefPause == 3) { // output to file stuff
      cout << "Write name of file to output to: " << endl;
      cin >> outputFile;
      while (generationNumber == 0 || !(doughnut->isEmpty(world, rows, columns)) && !(doughnut->getIsStable())){
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          doughnut->outputToFile(world, rows, columns, outputFile, generationNumber); //prints initial world
          generationNumber++;
        }
        doughnut->playDoughnutMode(world, rows, columns, briefPause, outputFile, generationNumber);
        generationNumber++;
      }
      cout << "Press enter to exit the program: ";
      cin.get();
      cin.get();
    } else {
      cout << "Must enter 1, 2, or 3!!!" << endl;
      return -1;
    }
  } else if (boundaryMode == 3) { //mirror mode
    if (briefPause == 1) { //brief pause stuff
      while (generationNumber == 0 || !(mirror->isEmpty(world, rows, columns)) && !(mirror->getIsStable())){
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          mirror->printWorld(world, rows, columns); //prints initial world
          generationNumber++;
        }
        mirror->playMirrorMode(world, rows, columns, briefPause, outputFile, generationNumber);
        generationNumber++;
        sleep_for(10ns);
        sleep_until(system_clock::now() + 1s);
      }
      cout << "Press enter to exit the program: ";
      cin.get();
      cin.get();
    } else if (briefPause == 2) { // press enter stuff
      cin.get();
      while (generationNumber == 0 || !(mirror->isEmpty(world, rows, columns)) && !(mirror->getIsStable())){
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          mirror->printWorld(world, rows, columns); //prints initial world
          generationNumber++;
        }
        mirror->playMirrorMode(world, rows, columns, briefPause, outputFile, generationNumber);
        generationNumber++;
        cin.get();
      }
      cout << "Press enter to exit the program: ";
      cin.get();
    } else if (briefPause == 3) { // output to file stuff
      cout << "Write name of file to output to: " << endl;
      cin >> outputFile;
      while (generationNumber == 0 || !(mirror->isEmpty(world, rows, columns)) && !(mirror->getIsStable())){
        if (generationNumber == 0) {
          cout << generationNumber << endl;
          mirror->outputToFile(world, rows, columns, outputFile, generationNumber); //prints initial world
          generationNumber++;
        }
        mirror->playMirrorMode(world, rows, columns, briefPause, outputFile, generationNumber);
        generationNumber++;
      }
      cout << "Press enter to exit the program: ";
      cin.get();
      cin.get();
    } else {
      cout << "Must enter 1, 2, or 3!!!" << endl;
      return -1;
    }
  } else {
    cout << "Must enter 1, 2, or 3!!!" << endl;
    return -1;
  }
  delete world;
  delete conf;
  delete classic;
  delete doughnut;
  delete mirror;
  return 0;
}
