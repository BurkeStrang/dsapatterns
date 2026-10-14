#include "nextgreaterelement.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {4, 5, 2, 25}, {5, 25, 25, -1}},
        {"Example 2", {13, 7, 6, 12}, {-1, 12, 12, -1}},
        {"Example 3", {1, 2, 3, 4, 5}, {2, 3, 4, 5, -1}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("next_larger_element()", next_larger_element(tt.arr), tt.want);
    }
    return t::done();
}
