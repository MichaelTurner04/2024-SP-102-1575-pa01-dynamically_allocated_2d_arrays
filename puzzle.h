#ifndef PUZZLE_H
#define PUZZLE_H

#include <ctime>
#include <stdlib.h>

/*
DO NOT ALTER THIS FILE IN ANY WAY
*/

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

  const Puzzle &operator=(const Puzzle &rhs);
  Puzzle(const Puzzle &source);
  ~Puzzle();

  void random_fill() {
    time_t seed;
    srand(time(&seed));
    if (symbols == nullptr)
      return;
    for (int r = 0; r < rows; r++)
      for (int c = 0; c < cols; c++)
        symbols[r][c] = rand() % 127 + 33;
  }

}; // WARNING: This class is not memory-safe

#endif
