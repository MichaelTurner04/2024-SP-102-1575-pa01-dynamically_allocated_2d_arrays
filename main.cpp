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
  char symbols;
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
    cin >> symbols;
    puzzle.fill_grid();
    // Read in moves (solve puzzle)
    ////////////////////////
    char a;
    char b;
    for (int i = 0; i < moves; i++) {
      cin >> a;
      cin >> b;
      if (b == 'R' || b == 'L') {
        if (b == 'R') {
          puzzle.shift_row(a, false);
        } else if (b == 'L') {
          puzzle.shift_row(a, true);
        }
      } else if (b == 'U' || b == 'D') {
        if (b == 'U') {
          puzzle.shift_col(a, true);
        } else if (b == 'D') {
          puzzle.shift_col(a, false);
        }
      }
    }

    ////////////////////////
    // Print Solution
    puzzle.print_grid();
    // De-allocate 2-D array
    puzzle.delete_grid();
    //// END YOUR CODE ////
  }

  return 0;
}