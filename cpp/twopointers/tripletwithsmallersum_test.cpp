#include "tripletwithsmallersum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int target;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {-1, 0, 2, 3}, 3, 2},
        {"Example 2", {-1, 4, 2, 1, 3}, 5, 4},
        {"empty", {}, 5, 0},
        {"two numbers", {1, 2}, 3, 0},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_triplets()", find_triplets(tt.arr, tt.target), tt.want);
    }
    return t::done();
}
