#include "mergeksortedlist.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> lists;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1",
         {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}},
         {1, 2, 3, 3, 4, 6, 6, 7, 8}},
        {"Example 2", {{5, 8, 9}, {1, 7}}, {1, 5, 7, 8, 9}},
        {"An empty list among them", {{}, {1}}, {1}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<ListNode *> lists;
        for (const std::vector<int> &values : tt.lists)
        {
            lists.push_back(build_list(values));
        }
        t::check("merge()", list_values(merge(lists)), tt.want);
    }
    return t::done();
}
