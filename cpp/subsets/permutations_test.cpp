#include "permutations.cpp"

#include "testing/testing.hpp"

#include <algorithm>

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"3 elements",
         {1, 2, 3},
         {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<std::vector<int>> got = find_permutations(tt.nums);
        // the permutations may come back in any order
        std::ranges::sort(got);
        t::check("find_permutations()", got, tt.want);
    }
    return t::done();
}
