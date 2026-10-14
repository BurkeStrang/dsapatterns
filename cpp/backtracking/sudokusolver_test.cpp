#include "sudokusolver.cpp"

#include "testing/testing.hpp"

int main()
{
    t::run("Example 1");
    // each row is written as a string, one character per cell
    std::vector<std::string> board = {
        "53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
        "7...2...6", ".6....28.", "...419..5", "....8..79",
    };
    std::vector<std::string> want = {
        "534678912", "672195348", "198342567", "859761423", "426853791",
        "713924856", "961537284", "287419635", "345286179",
    };

    solve_sudoku(board);

    t::check("solve_sudoku()", board, want);
    return t::done();
}
