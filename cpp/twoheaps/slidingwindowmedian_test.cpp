#include "slidingwindowmedian.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int k;
        std::vector<double> want;
    };
    std::vector<test> tests = {
        {"k=2", {1, 2, -1, 3, 5}, 2, {1.5, 0.5, 1.0, 4.0}},
        {"k=3", {1, 2, -1, 3, 5}, 3, {1.0, 2.0, 3.0}},
        {"single element window", {4, 1, 3}, 1, {4.0, 1.0, 3.0}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check_near("find_sliding_window_median()",
                      find_sliding_window_median(tt.nums, tt.k), tt.want);
    }
    return t::done();
}
