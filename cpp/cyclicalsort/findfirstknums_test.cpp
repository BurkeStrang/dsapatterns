#include "findfirstknums.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int k;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {3, -1, 4, 5, 5}, 3, {1, 2, 6}},
        {"Example 2", {2, 3, 4}, 3, {1, 5, 6}},
        {"Example 3", {-2, -3, 4}, 2, {1, 2}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_first_k()", find_first_k(tt.nums, tt.k), tt.want);
    }
    return t::done();
}
