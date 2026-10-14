#include "allpathsforsum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        int sum;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", 10, {{1, 3, 6}}},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]", 23, {{12, 1, 10}}},
        {"No path",
         "[5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1]",
         100,
         {}},
        {"Two paths",
         "[5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1]",
         22,
         {{5, 4, 11, 2}, {5, 8, 4, 5}}},
        {"Empty tree", "[]", 0, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_paths()", find_paths(tree(tt.root), tt.sum), tt.want);
    }
    return t::done();
}
