#include "connectropes.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> rope_lengths;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 2, 3, 4, 5}, 33},
        {"Example 2", {3, 4, 5, 6}, 36},
        {"Example 3", {1, 3, 11, 5, 2}, 42},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("minimum_cost_to_connect_ropes()",
                 minimum_cost_to_connect_ropes(tt.rope_lengths), tt.want);
    }
    return t::done();
}
