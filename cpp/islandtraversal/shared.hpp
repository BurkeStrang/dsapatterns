#pragma once

#include <vector>

// in_bounds reports whether (x, y) is a cell of the matrix. The traversals
// step one cell past every edge, so x and y may be -1 or one past the end.
template <typename T>
bool in_bounds(const std::vector<std::vector<T>> &matrix, int x, int y)
{
    return x >= 0 && x < std::ssize(matrix) && y >= 0 &&
           y < std::ssize(matrix[0]);
}
