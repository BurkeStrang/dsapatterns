#include "findallmissingnum.cpp"

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
        {"Example 1", {2, 3, 1, 8, 2, 3, 5, 1}, {4, 6, 7}},
        {"Example 2", {2, 4, 1, 2}, {3}},
        {"Example 3", {2, 3, 2, 1}, {4}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_numbers()", find_numbers(tt.nums), tt.want);
    }
    return t::done();
}
