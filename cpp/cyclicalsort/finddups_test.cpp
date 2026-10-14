#include "finddups.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {3, 4, 4, 5, 5}, {5, 4}},
        {"Example 2", {5, 4, 7, 2, 3, 5, 3}, {3, 5}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_dups()", find_dups(tt.nums), tt.want);
    }
    return t::done();
}
