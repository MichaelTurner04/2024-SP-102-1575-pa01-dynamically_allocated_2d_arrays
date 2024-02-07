#include "puzzle.h"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    int rows = 3, cols = 4;
    Puzzle p, test_p;
    p.create_grid(rows, cols);
    p.random_fill();
    test_p = p; // Deep Copy

    // reverse shift
    p.shift_col(2, true);
    if (p.grid()[0][2] != test_p.grid()[1][2] ||
        p.grid()[1][2] != test_p.grid()[2][2] ||
        p.grid()[2][2] != test_p.grid()[0][2])
      return false;

    return true;
  });
}
