#include "reconstructsequence.cpp"

#include "testing/testing.hpp"

#include <string>

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> original_seq;
        std::vector<std::vector<int>> sequences;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 2, 3, 4}, {{1, 2}, {2, 3}, {3, 4}}, true},
        {"Example 2", {1, 2, 3, 4}, {{1, 2}, {2, 3}, {2, 4}}, false},
        {"Example 3", {3, 1, 4, 2, 5}, {{3, 1, 5}, {1, 4, 2, 5}}, true},
        {"Different order", {1, 2, 3}, {{3, 2}, {2, 1}}, false},
        {"Missing number", {1, 2, 3}, {{1, 2}}, false},
        {"Cyclic sequences", {1, 2, 3}, {{1, 2}, {2, 3}, {3, 1}}, false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("can_construct()",
                 can_construct(tt.original_seq, tt.sequences), tt.want);
    }
    return t::done();
}
