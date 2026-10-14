#include "infinitearray.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int key;
        int want;
    };
    std::vector<int> evens; // 4, 6, ..., 30
    for (int value = 4; value <= 30; value += 2)
    {
        evens.push_back(value);
    }
    std::vector<test> tests = {
        {"Example 1", evens, 16, 6},
        {"Example 2", evens, 11, -1},
        {"Example 3", {1, 3, 8, 10, 15}, 15, 4},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        ArrayReader reader(tt.arr);
        t::check("search_infinite_sorted_array()",
                 search_infinite_sorted_array(reader, tt.key), tt.want);
    }
    return t::done();
}
