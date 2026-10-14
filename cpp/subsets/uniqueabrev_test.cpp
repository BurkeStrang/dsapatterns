#include "uniqueabrev.cpp"

#include "testing/testing.hpp"

#include <algorithm>

int main()
{
    struct test
    {
        std::string name;
        std::string word;
        std::vector<std::string> want;
    };
    std::vector<test> tests = {
        {"word",
         "word",
         {"word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d",
          "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        std::vector<std::string> got =
            generate_generalized_abbreviation(tt.word);
        // the abbreviations may come back in any order
        std::ranges::sort(got);
        std::ranges::sort(tt.want);
        t::check("generate_generalized_abbreviation()", got, tt.want);
    }
    return t::done();
}
