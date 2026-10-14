#include "maximumsub.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int k;
        std::vector<int> arr;
        int want;
    };
    std::vector<test> tests = {
        {"basic case", 3, {2, 1, 5, 1, 3, 2}, 9},
        {"single element window", 1, {4, 2, 7, 1}, 7},
        {"window equals array length", 4, {1, 2, 3, 4}, 10},
        {"empty array", 3, {}, 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_max_sum_sub_array()",
                 find_max_sum_sub_array(tt.k, tt.arr), tt.want);
    }
    return t::done();
}
