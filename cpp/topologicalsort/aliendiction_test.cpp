#include "aliendiction.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::string> words;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", {"ba", "bc", "ac", "cab"}, "bac"},
        {"Example 2", {"cab", "aaa", "aab"}, "cab"},
        {"Example 3", {"ywx", "wz", "xww", "xz", "zyy", "zwz"}, "ywxz"},
        {"Word before its own prefix", {"abc", "ab"}, ""},
        {"Cyclic ordering", {"a", "b", "a"}, ""},
        {"No words", {}, ""},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_alien_order()", find_alien_order(tt.words), tt.want);
    }
    return t::done();
}
