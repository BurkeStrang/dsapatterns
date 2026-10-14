#include "ksmallest.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> lists;
        int k;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}}, 5, 4},
        {"Example 2", {{5, 8, 9}, {1, 7}}, 3, 7},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_kth_smallest()", find_kth_smallest(tt.lists, tt.k),
                 tt.want);
    }
    return t::done();
}
