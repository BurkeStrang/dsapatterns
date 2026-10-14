#include "indexparis.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string text;
        std::vector<std::string> words;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Test Case 1",
         "thestarsareout",
         {"star", "stars", "are"},
         {{3, 6}, {3, 7}, {8, 10}}},
        {"Test Case 2",
         "bluebirdskyscraper",
         {"blue", "bird", "sky"},
         {{0, 3}, {4, 7}, {8, 10}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("index_pairs()", index_pairs(tt.text, tt.words), tt.want);
    }
    return t::done();
}
