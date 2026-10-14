#include "sumofelements.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int k1;
        int k2;
        int want;
    };
    std::vector<test> tests = {
        {"basic test", {1, 3, 12, 5, 15, 11}, 3, 6, 23},
        {"second test", {3, 5, 8, 7}, 1, 4, 12},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_sum_of_elements()",
                 find_sum_of_elements(tt.nums, tt.k1, tt.k2), tt.want);
    }
    return t::done();
}
