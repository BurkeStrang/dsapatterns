#include "dupsubsets.cpp"

#include "subsets/shared.hpp"
#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"example test case 1",
         {1, 3, 3},
         {{}, {1}, {3}, {1, 3}, {3, 3}, {1, 3, 3}}},
        {"example test case 2",
         {1, 2, 3},
         {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_dup_subsets()",
                 sorted_subsets(find_dup_subsets(tt.nums)),
                 sorted_subsets(tt.want));
    }
    return t::done();
}
