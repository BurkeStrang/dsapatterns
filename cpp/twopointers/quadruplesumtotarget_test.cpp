#include "quadruplesumtotarget.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int target;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1", {4, 1, 2, -1, 1, -3}, 1, {{-3, -1, 1, 4}, {-3, 1, 1, 2}}},
        {"Example 2", {2, 0, -1, 1, -2, 2}, 2, {{-2, 0, 2, 2}, {-1, 0, 1, 2}}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        std::vector<std::vector<int>> got =
            search_quadruplets(tt.arr, tt.target);
        // the quadruplets may come back in any order
        std::ranges::sort(got);
        t::check("search_quadruplets()", got, tt.want);
    }
    return t::done();
}
