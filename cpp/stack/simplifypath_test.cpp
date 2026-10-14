#include "simplifypath.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string path;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", "/a//b////c/d//././/..", "/a/b/c"},
        {"Example 2", "/../", "/"},
        {"Example 3", "/home//foo/", "/home/foo"},
        {"Root only", "/", "/"},
        {"Multiple .. at root", "/../../..", "/"},
        {"Dot only", "/./././.", "/"},
        {"Trailing slash", "/a/b/c/", "/a/b/c"},
        {"Complex", "/a/./b/../../c/", "/c"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("simplify_path()", simplify_path(tt.path), tt.want);
    }
    return t::done();
}
