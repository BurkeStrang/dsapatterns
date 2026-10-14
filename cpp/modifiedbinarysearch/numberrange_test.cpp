#include "numberrange.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int key;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"example1", {4, 6, 6, 6, 9}, 6, {1, 3}},
        {"example2", {1, 3, 8, 10, 15}, 10, {3, 3}},
        {"example3", {1, 3, 8, 10, 15}, 12, {-1, -1}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_range()", find_range(tt.arr, tt.key), tt.want);
    }
    return t::done();
}
