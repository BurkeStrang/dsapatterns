#include "housetheif.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> wealth;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {2, 5, 1, 3, 6, 2, 4}, 15},
        {"Example 2", {2, 10, 14, 8, 1}, 18},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_max_steal()", find_max_steal(tt.wealth), tt.want);
    }
    return t::done();
}
