#include "removedup.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", "babac", "abc"},
        {"Example 2", "zabccde", "zabcde"},
        {"Example 3", "mnopmn", "mnop"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("remove_duplicate_letters()", remove_duplicate_letters(tt.s),
                 tt.want);
    }
    return t::done();
}
