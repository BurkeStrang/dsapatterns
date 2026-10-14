#include "reversesublist.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> head;
        int p;
        int q;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"reverse middle sublist", {1, 2, 3, 4, 5}, 2, 4, {1, 4, 3, 2, 5}},
        {"reverse entire list", {1, 2, 3}, 1, 3, {3, 2, 1}},
        {"reverse single node (no change)", {1, 2}, 2, 2, {1, 2}},
        {"reverse head only", {1, 2}, 1, 1, {1, 2}},
        {"reverse first two", {1, 2, 3}, 1, 2, {2, 1, 3}},
        {"reverse last two", {1, 2, 3}, 2, 3, {1, 3, 2}},
        {"empty list", {}, 1, 1, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        ListNode *got = reverse_sub(build_list(tt.head), tt.p, tt.q);
        t::check("reverse_sub()", list_values(got), tt.want);
    }
    return t::done();
}
