#include "dailytemp.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> temperatures;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1",
         {70, 73, 75, 71, 69, 72, 76, 73},
         {1, 1, 4, 2, 1, 1, 0, 0}},
        {"Example 2", {73, 72, 71, 70}, {0, 0, 0, 0}},
        {"Example 3", {70, 71, 72, 73}, {1, 1, 1, 0}},
        {"All same", {60, 60, 60}, {0, 0, 0}},
        {"Single element", {80}, {0}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("daily_temperatures()", daily_temperatures(tt.temperatures),
                 tt.want);
    }
    return t::done();
}
