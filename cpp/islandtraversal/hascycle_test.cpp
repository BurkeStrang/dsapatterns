#include "hascycle.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<char>> matrix;
        bool want;
    };
    std::vector<test> tests = {
        {"no cycle",
         {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}},
         false},
        {"simple cycle",
         {{'A', 'A', 'A'}, {'A', 'B', 'A'}, {'A', 'A', 'A'}},
         true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("has_cycle()", has_cycle(tt.matrix), tt.want);
    }
    return t::done();
}
