#include "diffwaystoevaluate.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string input;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"parentheses addition", "2+3*2", {8, 10}},
        {"parentheses multiple", "2*4-3*5", {-22, 10, -7, 10, 25}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("diff_ways_to_evaluate_expression()",
                 diff_ways_to_evaluate_expression(tt.input), tt.want);
    }
    return t::done();
}
