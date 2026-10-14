#include "mediannumberstream.cpp"

#include "testing/testing.hpp"

#include <string>
#include <utility>

int main()
{
    struct test
    {
        std::string name;
        // each number to insert, and the median after inserting it
        std::vector<std::pair<int, double>> steps;
    };
    std::vector<test> tests = {
        {"in order", {{1, 1.0}, {2, 1.5}, {3, 2.0}, {4, 2.5}, {5, 3.0}}},
        {"unordered", {{5, 5.0}, {3, 4.0}, {8, 5.0}, {1, 4.0}, {2, 3.0}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        Median m;
        for (auto [num, want] : tt.steps)
        {
            m.insert_num(num);
            t::check_near("find_median() after inserting " +
                              std::to_string(num),
                          m.find_median(), want);
        }
    }
    return t::done();
}
