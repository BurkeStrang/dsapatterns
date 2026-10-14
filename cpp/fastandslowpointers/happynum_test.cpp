#include "happynum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int num;
        bool want;
    };
    std::vector<test> tests = {
        {"Happy number 19", 19, true},
        {"Happy number 1", 1, true},
        {"Unhappy number 2", 2, false},
        {"Unhappy number 4", 4, false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("is_happy()", is_happy(tt.num), tt.want);
    }
    return t::done();
}
