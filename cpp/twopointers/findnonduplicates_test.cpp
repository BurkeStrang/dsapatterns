#include "findnonduplicates.cpp"

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
        {"Example 1", {2, 3, 3, 3, 6, 9, 9}, {2, 3, 6, 9}},
        {"Example 2", {2, 2, 2, 11}, {2, 11}},
        {"duplicate at the end", {1, 2, 2}, {1, 2}},
        {"many duplicates", {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, {0, 1, 2, 3, 4}},
        {"single element", {1}, {1}},
        {"no duplicates", {1, 2, 3}, {1, 2, 3}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        int got = move_elements(tt.arr);
        tt.arr.resize(got);
        t::check("move_elements()", tt.arr, tt.want);
    }
    return t::done();
}
