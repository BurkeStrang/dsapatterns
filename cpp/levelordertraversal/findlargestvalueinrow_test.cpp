#include "findlargestvalueinrow.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 2, 3, 4, 5, null, 6]", {1, 3, 6}},
        {"Example 2", "[7, 4, 8, 2, 5, null, 9, null, 3]", {7, 8, 9, 3}},
        {"Example 3", "[10, 5]", {10, 5}},
        {"Empty tree", "[]", {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("largest_values()", largest_values(tree(tt.root)), tt.want);
    }
    return t::done();
}
