#include "tripletessumzero.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1",
         {-3, 0, 1, 2, -1, 1, -2},
         {{-3, 1, 2}, {-2, 0, 2}, {-2, 1, 1}, {-1, 0, 1}}},
        {"Example 2", {-5, 2, -1, -2, 3}, {{-5, 2, 3}, {-2, -1, 3}}},
        {"No triplets", {1, 2, 3}, {}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        std::vector<std::vector<int>> got = search_triplets(tt.arr);
        // the triplets may come back in any order
        std::ranges::sort(got);
        t::check("search_triplets()", got, tt.want);
    }
    return t::done();
}
