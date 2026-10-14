#include "pairwithtargetsum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int target;
        std::optional<std::pair<int, int>> want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 2, 3, 4, 6}, 6, std::pair{1, 3}},
        {"Example 2", {2, 5, 9, 11}, 11, std::pair{0, 2}},
        {"No pair", {1, 2, 3, 4, 5}, 10, std::nullopt},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("search()", search(tt.arr, tt.target), tt.want);
    }
    return t::done();
}
