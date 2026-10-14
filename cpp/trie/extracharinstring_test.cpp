#include "extracharinstring.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        std::vector<std::string> dictionary;
        int want;
    };
    std::vector<test> tests = {
        {"Test Case 1", "amazingracecar", {"race"}, 10},
        {"Test Case 2", "amazingracecar", {"race", "car"}, 7},
        {"Test Case 3", "bookkeeperreading", {"keep", "read"}, 9},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("min_extra_char()", min_extra_char(tt.s, tt.dictionary),
                 tt.want);
    }
    return t::done();
}
