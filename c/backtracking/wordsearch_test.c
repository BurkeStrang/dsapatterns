#include "wordsearch.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *board[3]; // one string per row
        const char *word;
        bool want;
    } tests[] = {
        {"test1", {"ABCE", "SFCS", "ADEE"}, "ABCCED", true},
        {"test2", {"ABCE", "SFCS", "ADEE"}, "SEE", true},
        {"test3", {"ABCE", "SFCS", "ADEE"}, "XYZ", false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        // the search changes cells as it goes, so give it a copy it can write
        char rows[3][8];
        char *board[3];
        for (int row = 0; row < 3; row++)
        {
            strcpy(rows[row], tt->board[row]);
            board[row] = rows[row];
        }
        bool got = exist(board, 3, tt->word);
        t_check_bool("exist()", got, tt->want);
    }
    return t_done();
}
