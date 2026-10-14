#include "removeadjactentdupsii.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        int k;
        std::string want;
    };
    std::vector<test> tests = {
        {"remove bbb then aaa", "abbbaaca", 3, "ca"},
        {"no removal possible", "abbaccaa", 3, "abbaccaa"},
        {"remove ccc then aaa", "abbacccaa", 3, "abb"},
        {"all removed", "aaa", 3, ""},
        {"single char, k=2", "a", 2, "a"},
        {"multiple removals", "deeedbbcccbdaa", 3, "aa"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("remove_duplicates_ii()", remove_duplicates_ii(tt.s, tt.k),
                 tt.want);
    }
    return t::done();
}
