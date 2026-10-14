#include "reverseksublist.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> head;
        int k;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"reverse every 2 nodes", {1, 2, 3, 4, 5}, 2, {2, 1, 4, 3, 5}},
        {"reverse every 3 nodes", {1, 2, 3, 4, 5}, 3, {3, 2, 1, 5, 4}},
        {"k greater than length", {1, 2}, 5, {2, 1}},
        {"single node", {1}, 2, {1}},
        {"empty list", {}, 2, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        ListNode *got = reverse_k_sub(build_list(tt.head), tt.k);
        t::check("reverse_k_sub()", list_values(got), tt.want);
    }
    return t::done();
}
