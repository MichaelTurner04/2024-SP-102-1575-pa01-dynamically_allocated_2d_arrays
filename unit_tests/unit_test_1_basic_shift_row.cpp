#include "puzzle.h"
#include "test_utils.hpp"

int main(const int argc, const char **argv) {
  return test_wrapper(argc, argv, []() {
    int rows = 3, cols = 3;
    Puzzle p;
    Puzzle test_p;
    p.create_grid(rows, cols);
    p.random_fill();
    test_p = p; // deep copy

    // basic shift
    p.shift_row(0);
    if (p.grid()[0][0] != test_p.grid()[0][2] ||
        p.grid()[0][1] != test_p.grid()[0][0] ||
        p.grid()[0][2] != test_p.grid()[0][1])
      return false;

    return true;
  });
}
