#include "countpathssum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        int target_sum;
        int want;
    };
    std::vector<test> tests = {
        // Paths: [1,2], [3]
        {"Example 1: Two paths", "[1, 2, 3]", 3, 2},
        // Paths: [5,3], [5,2,1], [-3,11]
        {"Example 2: Multiple paths",
         "[10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]", 8, 3},
        {"Example 3: No path", "[1, 2]", 100, 0},
        {"Example 4: Empty tree", "[]", 0, 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("count_paths()", count_paths(tree(tt.root), tt.target_sum),
                 tt.want);
    }
    return t::done();
}
