#include "maxsum.cpp"

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
        // 2 + 1 + 3
        {"simple tree", "[1, 2, 3]", 6},
        // 15 + 20 + 7
        {"tree with negative values", "[-10, 9, 20, null, null, 15, 7]", 42},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_maximum_path_sum()",
                 find_maximum_path_sum(tree(tt.root)), tt.want);
    }
    return t::done();
}
