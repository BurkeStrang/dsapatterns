#include "corruptpair.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        std::optional<std::pair<int, int>> want;
    };
    std::vector<test> tests = {
        {"Example 1", {3, 1, 2, 5, 2}, std::pair{2, 4}},
        {"Example 2", {3, 1, 2, 3, 6, 4}, std::pair{3, 5}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_corrupt()", find_corrupt(tt.nums), tt.want);
    }
    return t::done();
}
