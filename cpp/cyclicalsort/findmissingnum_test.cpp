#include "findmissingnum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {4, 0, 3, 1}, 2},
        {"Example 2", {8, 3, 5, 2, 4, 6, 0, 1}, 7},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_missing_number()", find_missing_number(tt.nums),
                 tt.want);
    }
    return t::done();
}
