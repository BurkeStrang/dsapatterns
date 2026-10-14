#include "reverse.cpp"

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
        {"multiple nodes", {1, 2, 3}, {3, 2, 1}},
        {"single node", {1}, {1}},
        {"empty list", {}, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        ListNode *got = reverse(build_list(tt.head));
        t::check("reverse()", list_values(got), tt.want);
    }
    return t::done();
}
