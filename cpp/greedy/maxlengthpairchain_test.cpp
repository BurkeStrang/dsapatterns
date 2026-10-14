#include "maxlengthpairchain.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::array<int, 2>> pairs;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {{1, 2}, {3, 4}, {2, 3}}, 2},
        {"Example 2", {{5, 6}, {1, 2}, {8, 9}, {2, 3}}, 3},
        {"Example 3", {{7, 8}, {5, 6}, {1, 2}, {3, 5}, {4, 5}, {2, 3}}, 3},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_longest_chain()", find_longest_chain(tt.pairs), tt.want);
    }
    return t::done();
}
