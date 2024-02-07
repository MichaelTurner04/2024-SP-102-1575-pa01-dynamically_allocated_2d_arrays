#include "../../puzzle.cpp"
#include <ctime>
#include <stdlib.h>

int main() {

  time_t seed;
  srand(time(&seed));

  int cols = rand() % 50 + 2;
  int rows = rand() % 50 + 2;

  Puzzle p;

  p.create_grid(rows, cols);
  p.shift_row(0);
  p.shift_row(1, true);
  p.shift_col(0);
  p.shift_col(1, true);
  p.delete_grid();

  return 0;
}
