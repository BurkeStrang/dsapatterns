#include "topkfrequent.cpp"

#include "testing/testing.hpp"

#include <algorithm>

int main()
{
    // numbers with the same frequency may be picked in any order, so each
    // case lists every number that is allowed in the result
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int k;
        std::vector<int> valid;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 3, 5, 12, 11, 12, 11}, 2, {11, 12}},
        {"Example 2", {5, 12, 11, 3, 11}, 2, {11, 5, 12, 3}},
        {"Example 3", {1, 1, 1, 3, 3, 3, 5, 5, 5, 12}, 2, {1, 3, 5}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<int> got = find_top_k_frequent_numbers(tt.nums, tt.k);
        t::check("length of find_top_k_frequent_numbers()", std::ssize(got),
                 static_cast<std::ptrdiff_t>(tt.k));
        for (int v : got)
        {
            if (std::ranges::find(tt.valid, v) == tt.valid.end())
            {
                t::errorf("unexpected {} in {}", v, t::str(got));
            }
        }
    }
    return t::done();
}
