#include "puzzle.h"
#include <iostream>
using namespace std;

/*  FOR REFERENCE ONLY. DO NOT UNCOMMENT
class Puzzle {

private:
  int rows, cols;
  char **symbols;

public:
  Puzzle() : rows(0), cols(0), symbols(nullptr) {}

  char **grid() { return symbols; }
  const int &get_rows() const { return rows; }
  const int &get_cols() const { return cols; }

  void create_grid(int rows, int cols);
  void fill_grid();
  void delete_grid();
  void print_grid() const;
  void shift_row(int row, bool reverse = false);
  void shift_col(int col, bool reverse = false);
  ...
}
*/

/*
Purpose: turn symbols into r-by-c dynamic char array, and set members rows/cols
accordingly Tested by: unit_tests/unit_test_0 Post-conditions:
  - symbols points to r-by-c dynamic array
  - rows == r
  - cols == c
*/
void Puzzle::create_grid(int r, int c) {
  rows = r;
  cols = c;
  symbols = new char *[r];
  for (int i = 0; i < r; i++) {
    symbols[i] = new char[c];
  }
}

/*
Purpose: de-allocates symbols, and sets symbols to nullptr
Tested by: mem_tests
*/
void Puzzle::delete_grid() {
  for (int i = 0; i < rows; i++) {
    delete[] symbols[i];
  }
  delete[] symbols;
  symbols = nullptr;
}

/*
Purpose: shifts a row of symbols (right if reverse = false, left if reverse =
true), wrapping the furthest symbol around
Tested by: unit_tests/unit_test_1-3
*/
void Puzzle::shift_row(int row, bool reverse) {
  if (reverse == false) {
    char temp = symbols[row][cols - 1];
    for (int i = cols - 1; i > 0; i--) {
      symbols[row][i] = symbols[row][i - 1];
    }
    symbols[row][0] = temp;
  } else if (reverse == true) {
    char temp = symbols[row][0];
    for (int i = 0; i < cols - 1; i++) {
      symbols[row][i] = symbols[row][i + 1];
    }
    symbols[row][cols - 1] = temp;
  }
}

/*
Purpose: shifts a column of symbols (down if reverse = false, up if reverse =
true), wrapping the furthest symbol around
Tested by: unit_tests/unit_test_4-6
*/
void Puzzle::shift_col(int col, bool reverse) {
  if (reverse == false) {
    char temp = symbols[rows - 1][col];
    for (int i = rows - 1; i > 0; i--) {
      symbols[i][col] = symbols[i - 1][col];
    }
    symbols[0][col] = temp;
  } else if (reverse == true) {
    char temp = symbols[0][col];
    for (int i = 0; i < rows - 1; i++) {
      symbols[i][col] = symbols[i + 1][col];
    }
    symbols[rows - 1][col] = temp;
  }
}

// These functions are given to you, no need to change them

/*
Purpose: Read in symbols to initialize puzzle
PROVIDED FOR YOU, no need to change
*/
void Puzzle::fill_grid() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> symbols[i][j];
    }
  }
}

/*
Purpose: Print contents of puzzle
PROVIDED FOR YOU, no need to change
*/
void Puzzle::print_grid() const {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++)
      cout << symbols[i][j] << " ";
    cout << endl;
  }
  cout << endl;
}

// Default Member Functions

const Puzzle &Puzzle::operator=(const Puzzle &rhs) {
  // Performs a deep-copy of a Puzzle object

  delete_grid();
  create_grid(rhs.rows, rhs.cols);
  for (int r = 0; r < rhs.rows; r++)
    for (int c = 0; c < rhs.cols; c++)
      symbols[r][c] = rhs.symbols[r][c];

  return *this;
}

Puzzle::Puzzle(const Puzzle &source) {

  symbols = nullptr;
  *this = source; // invokes operator=
}

Puzzle::~Puzzle() {
  // De-allocates dynamic member variables

  if (symbols != nullptr)
    delete_grid();
}
