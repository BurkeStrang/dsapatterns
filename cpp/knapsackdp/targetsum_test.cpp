#include "targetsum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> num;
        int s;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 1, 2, 3}, 1, 3},
        {"Example 2", {1, 2, 7, 1}, 9, 2},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_target_subsets()", find_target_subsets(tt.num, tt.s),
                 tt.want);
    }
    return t::done();
}
