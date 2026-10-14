#include "sumofpathnums.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        int want;
    };
    std::vector<test> tests = {
        // Paths: 12, 13 => 12+13=25
        {"Example 1", "[1, 2, 3]", 25},
        // Paths: 101, 106, 115 => 101+106+115=322
        //                       1
        //                     /   \
        //                    0     1
        //                   / \     \
        //                  1   6     5
        {"Example 2", "[1, 0, 1, 1, 6, null, 5]", 322},
        {"Single node", "[5]", 5},
        {"Empty tree", "[]", 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_sum_of_path_numbers()",
                 find_sum_of_path_numbers(tree(tt.root)), tt.want);
    }
    return t::done();
}
