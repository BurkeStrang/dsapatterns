#include "comparingstringsbackslash.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string str1;
        std::string str2;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", "xy#z", "xzz#", true},
        {"Example 2", "xy#z", "xyz#", false},
        {"Example 3", "xp#", "xyz##", true},
        {"Example 4", "xywrrmp", "xywrrmu#p", true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("compare()", compare(tt.str1, tt.str2), tt.want);
    }
    return t::done();
}
