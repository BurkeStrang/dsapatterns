#include "maxnumballoons.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string text;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", "balloonballoon", 2},
        {"Example 2", "bbaall", 0},
        {"Example 3", "balloonballoooon", 2},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("max_number_of_balloons()", max_number_of_balloons(tt.text),
                 tt.want);
    }
    return t::done();
}
