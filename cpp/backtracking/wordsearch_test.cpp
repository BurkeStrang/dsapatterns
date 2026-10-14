#include "wordsearch.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string word;
        bool want;
    };
    // each row of the board is written as a string, one letter per cell
    std::vector<std::string> board = {"ABCE", "SFCS", "ADEE"};
    std::vector<test> tests = {
        {"test1", "ABCCED", true},
        {"test2", "SEE", true},
        {"test3", "XYZ", false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("exist()", exist(board, tt.word), tt.want);
        t::check("board after exist()", board,
                 std::vector<std::string>{"ABCE", "SFCS", "ADEE"});
    }
    return t::done();
}
