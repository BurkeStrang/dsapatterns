#include "minjumpswithfee.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> fee;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 2, 5, 2, 1, 2}, 3},
        {"Example 2", {2, 3, 4, 5}, 5},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_min_fee()", find_min_fee(tt.fee), tt.want);
    }
    return t::done();
}
