#include "puzzle.h"
#include <iostream>
using namespace std;
#include <string>

/*
Start by implementing puzzle.cpp functions

Once unit_tests are passing,
Use puzzle functions here to pass stdio_tests
*/

int main() {
  int puzzles;
  char symbols;
  cin >> puzzles;
  Puzzle puzzle; // Use this puzzle object ONLY, don't create extras

  for (int k = 0; k < puzzles; k++) {
    //// YOUR CODE HERE ////
    int rows;
    int cols;
    int moves;
    // Read in rows, cols, moves
    cin >> rows >> cols >> moves;
    // Allocate 2-D array
    puzzle.create_grid(rows, cols);
    // Read in symbols
    cin >> symbols;
    puzzle.fill_grid();
    // Read in moves (solve puzzle)
    ////////////////////////
    /*getline(cin, killMe);
      num1 = static_cast<int>(killMe[0]);
      if (killMe[1] != ' ') {
        num1 += static_cast<int>(killMe[1]);
        dir = killMe[3];
      } else {
        dir = killMe[2];
      }*/
    /*while (cin >> num1 >> dir) {
      cout << num1 << ", " << dir << endl;

      if (dir == 'R') {
        puzzle.shift_row(num1, false);
      } else if (dir == 'L') {
        puzzle.shift_row(num1, true);
      } else if (dir == 'U') {
        puzzle.shift_col(num1, true);
      } else if (dir == 'D') {
        puzzle.shift_col(num1, false);
      } else {
        cout << "error" << endl;
      }
    }*/
    for (int i = 0; i < moves; i++) {
      int num1;
      char dir;
      string killMe;
      getline(cin, killMe);
      num1 = killMe[0];
      dir = killMe[2];
      /*if (killMe[1] != ' ') {
        num1 += killMe[1];
        dir = killMe[3];
      } else {
        dir = killMe[2];
      }*/

      cout << num1 << ", " << dir << endl;

      /*if (dir == 'R') {
        puzzle.shift_row(num1, false);
      } else if (dir == 'L') {
        puzzle.shift_row(num1, true);
      } else if (dir == 'U') {
        puzzle.shift_col(num1, true);
      } else if (dir == 'D') {
        puzzle.shift_col(num1, false);
      } else {
        cout << "error" << endl;
      }*/
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