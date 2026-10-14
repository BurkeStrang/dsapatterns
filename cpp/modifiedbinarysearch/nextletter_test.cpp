#include "nextletter.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<char> letters;
        char key;
        char want;
    };
    std::vector<test> tests = {
        {"key in middle of array", {'a', 'c', 'f', 'h'}, 'f', 'h'},
        {"key before first element", {'a', 'c', 'f', 'h'}, 'b', 'c'},
        {"key is smallest element", {'a', 'c', 'f', 'h'}, 'a', 'c'},
        {"key is largest element - wraps around",
         {'a', 'c', 'f', 'h'},
         'h',
         'a'},
        {"key larger than all - wraps around", {'a', 'c', 'f', 'h'}, 'z', 'a'},
        {"key smaller than all elements", {'c', 'f', 'j'}, 'a', 'c'},
        {"key between two adjacent elements", {'a', 'c', 'f', 'h'}, 'g', 'h'},
        {"single element - wraps around", {'m'}, 'm', 'm'},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("search_next_letter()", search_next_letter(tt.letters, tt.key),
                 tt.want);
    }
    return t::done();
}
