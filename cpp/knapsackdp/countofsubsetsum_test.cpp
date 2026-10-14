#include "countofsubsetsum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> num;
        int sum;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 1, 2, 3}, 4, 3},
        {"Example 2", {1, 2, 7, 1, 5}, 9, 3},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("count_subsets()", count_subsets(tt.num, tt.sum), tt.want);
    }
    return t::done();
}
