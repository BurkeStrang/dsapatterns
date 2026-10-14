#include "pathwithsequence.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        std::vector<int> sequence;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1: Path exists",
         "[1, 7, 9, null, null, 2, 9]",
         {1, 9, 9},
         true},
        {"Example 2: Path does not exist",
         "[1, 0, 1, 1, 6, null, 5]",
         {1, 0, 7},
         false},
        {"Example 3: Empty sequence", "[1, 2]", {}, false},
        {"Example 4: Empty tree", "[]", {1}, false},
        {"Example 5: Single node match", "[5]", {5}, true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_path()", find_path(tree(tt.root), tt.sequence), tt.want);
    }
    return t::done();
}
