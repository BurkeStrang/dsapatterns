#include "reversestring.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string input;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", "Hello, World!", "!dlroW ,olleH"},
        {"Example 2", "OpenAI", "IAnepO"},
        {"Example 3", "Stacks are fun!", "!nuf era skcatS"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("reverse_string()", reverse_string(tt.input), tt.want);
    }
    return t::done();
}
