#include "puzzle.h"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    int rows = 3, cols = 2;
    Puzzle p, test_p;
    p.create_grid(rows, cols);
    p.random_fill();
    test_p = p; // Deep copy

    // multiple shifts
    p.shift_col(1);
    p.shift_col(1);
    p.shift_col(1);
    p.shift_col(1);
    if (p.grid()[0][1] != test_p.grid()[2][1] ||
        p.grid()[1][1] != test_p.grid()[0][1] ||
        p.grid()[2][1] != test_p.grid()[1][1])
      return false;

    return true;
  });
}
