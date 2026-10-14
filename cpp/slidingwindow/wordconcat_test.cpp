#include "wordconcat.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        std::vector<std::string> words;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", "catfoxcat", {"cat", "fox"}, {0, 3}},
        {"Example 2", "catcatfoxfox", {"cat", "fox"}, {3}},
        {"No match", "abcdefg", {"hi", "jk"}, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_word_concatenation()",
                 find_word_concatenation(tt.s, tt.words), tt.want);
    }
    return t::done();
}
