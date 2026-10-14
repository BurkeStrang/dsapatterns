#include "fruitsintobaskets.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<char> arr;
        int want;
    };
    std::vector<test> tests = {
        {"basic example", {'A', 'B', 'C', 'A', 'C'}, 3},
        {"all same fruit", {'A', 'A', 'A', 'A'}, 4},
        {"two types alternating", {'A', 'B', 'A', 'B', 'A', 'B'}, 6},
        {"three types", {'A', 'B', 'C', 'B', 'B', 'C', 'A'}, 5},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("max_fruit()", max_fruit(tt.arr), tt.want);
    }
    return t::done();
}
