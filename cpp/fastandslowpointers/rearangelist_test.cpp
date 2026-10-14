#include "rearangelist.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> head;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"even length list", {1, 2, 3, 4}, {1, 4, 2, 3}},
        {"odd length list", {1, 2, 3}, {1, 3, 2}},
        {"single node", {1}, {1}},
        {"empty list", {}, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        ListNode *got = rearange_list(build_list(tt.head));
        t::check("rearange_list()", list_values(got), tt.want);
    }
    return t::done();
}
