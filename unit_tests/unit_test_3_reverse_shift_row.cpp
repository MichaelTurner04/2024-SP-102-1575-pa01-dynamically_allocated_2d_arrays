#include "puzzle.h"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    int rows = 4, cols = 3;
    Puzzle p, test_p;
    p.create_grid(rows, cols);
    p.random_fill();
    test_p = p; // Deep copy

    // reverse shift
    p.shift_row(2, true);
    if (p.grid()[2][0] != test_p.grid()[2][1] ||
        p.grid()[2][1] != test_p.grid()[2][2] ||
        p.grid()[2][2] != test_p.grid()[2][0])
      return false;

    return true;
  });
}
