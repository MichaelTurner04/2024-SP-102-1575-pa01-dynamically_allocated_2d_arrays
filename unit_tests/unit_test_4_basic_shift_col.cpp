#include "puzzle.h"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    int rows = 3, cols = 3;
    Puzzle p, test_p;
    p.create_grid(rows, cols);
    p.random_fill();
    test_p = p; // Deep copy

    // basic shift
    p.shift_col(0);
    if (p.grid()[0][0] != test_p.grid()[2][0] ||
        p.grid()[1][0] != test_p.grid()[0][0] ||
        p.grid()[2][0] != test_p.grid()[1][0])
      return false;

    return true;
  });
}
