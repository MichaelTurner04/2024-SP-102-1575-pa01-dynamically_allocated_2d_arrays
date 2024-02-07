#include "puzzle.h"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    int rows = 2, cols = 3;
    Puzzle p, test_p;
    p.create_grid(rows, cols);
    p.random_fill();
    test_p = p; // Deep copy

    // multiple shifts
    p.shift_row(1);
    p.shift_row(1);
    p.shift_row(1);
    p.shift_row(1);
    if (p.grid()[1][0] != test_p.grid()[1][2] ||
        p.grid()[1][1] != test_p.grid()[1][0] ||
        p.grid()[1][2] != test_p.grid()[1][1])
      return false;

    return true;
  });
}
