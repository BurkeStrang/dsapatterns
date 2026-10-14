#include "stringanagrams.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        std::string pattern;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", "ppqp", "pq", {1, 2}},
        {"Example 2", "abbcabc", "abc", {2, 3, 4}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_string_anagrams()",
                 find_string_anagrams(tt.s, tt.pattern), tt.want);
    }
    return t::done();
}
