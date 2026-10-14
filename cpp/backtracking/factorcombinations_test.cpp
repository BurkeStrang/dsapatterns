#include "factorcombinations.cpp"

#include "testing/testing.hpp"

#include <algorithm>

int main()
{
    struct test
    {
        std::string name;
        int n;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1", 8, {{2, 2, 2}, {2, 4}}},
        {"Example 2", 20, {{2, 2, 5}, {2, 10}, {4, 5}}},
        {"A prime has none", 7, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<std::vector<int>> got = get_factors(tt.n);
        // the combinations may come back in any order
        std::ranges::sort(got);
        t::check("get_factors()", got, tt.want);
    }
    return t::done();
}
