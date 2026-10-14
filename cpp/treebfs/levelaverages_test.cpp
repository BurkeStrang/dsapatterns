#include "levelaverages.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        std::vector<double> want;
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", {1.0, 2.5, 5.5}},
        {"Example 2", "[12, 7, 1, null, 9, 10, 5]", {12.0, 4.0, 8.0}},
        {"Empty tree", "[]", {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check_near("level_average()", level_average(tree(tt.root)), tt.want);
    }
    return t::done();
}
