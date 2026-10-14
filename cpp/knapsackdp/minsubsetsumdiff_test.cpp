#include "minsubsetsumdiff.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> num;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 2, 3, 9}, 3},
        {"Example 2", {1, 2, 7, 1, 5}, 0},
        {"Example 3", {1, 3, 100, 4}, 92},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("can_partition_min()", can_partition_min(tt.num), tt.want);
    }
    return t::done();
}
