#include "sudokusolver.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *board[9]; // one string per row, with . for an empty cell
        const char *want[9];
    } tests[] = {
        {"Example 1",
         {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1",
          "7...2...6", ".6....28.", "...419..5", "....8..79"},
         {"534678912", "672195348", "198342567", "859761423", "426853791",
          "713924856", "961537284", "287419635", "345286179"}},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        Board board;
        for (int row = 0; row < 9; row++)
        {
            strcpy(board[row], tt->board[row]);
        }
        solve_sudoku(board);
        for (int row = 0; row < 9; row++)
        {
            if (strcmp(board[row], tt->want[row]) != 0)
            {
                t_errorf("row %d = \"%s\", want \"%s\"", row, board[row],
                         tt->want[row]);
            }
        }
    }
    return t_done();
}
