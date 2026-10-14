#include "fibonaccinumbers.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int n;
        long long want;
    };
    std::vector<test> tests = {
        {"Example 1", 0, 0}, {"Example 2", 1, 1},
        {"Example 3", 2, 1}, {"Example 4", 3, 2},
        {"Example 5", 4, 3}, {"Example 6", 55, 139583862445},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("calculate_fibonacci()", calculate_fibonacci(tt.n), tt.want);
    }
    return t::done();
}
