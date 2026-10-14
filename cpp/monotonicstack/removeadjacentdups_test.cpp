#include "removeadjacentdups.cpp"

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
        {"empty string", "", ""},
        {"no duplicates", "abcd", "abcd"},
        {"all removed", "abccba", ""},
        {"simple pair", "aabb", ""},
        {"single removal", "foobar", "fbar"},
        {"triple duplicate", "fooobar", "fobar"},
        {"nested removals", "azxxzy", "ay"},
        {"single char", "a", "a"},
        {"all same", "aaaa", ""},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("remove_duplicates()", remove_duplicates(tt.s), tt.want);
    }
    return t::done();
}
