#include "puzzle.h"
#include <iostream>
using namespace std;

/*
Start by implementing puzzle.cpp functions

Once unit_tests are passing,
Use puzzle functions here to pass stdio_tests
*/

int main() {
  int puzzles;
  int rows;
  int cols;
  int moves;
  cin >> puzzles;
  Puzzle puzzle; // Use this puzzle object ONLY, don't create extras

  for (int k = 0; k < puzzles; k++) {
    //// YOUR CODE HERE ////
    // Read in rows, cols, moves
    cin >> rows;
    cin >> cols;
    cin >> moves;
    // Allocate 2-D array
    puzzle.create_grid(rows, cols);
    // Read in symbols
    // Read in moves (solve puzzle)
    ////////////////////////

    ////////////////////////
    // Print Solution
    puzzle.delete_grid();
    // De-allocate 2-D array
    //// END YOUR CODE ////
  }

  return 0;
}