#include "removenodesfromlinkedlist.cpp"

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
        {"Example 1", {5, 3, 7, 4, 2, 1}, {7, 4, 2, 1}},
        {"Example 2", {1, 2, 3, 4, 5}, {5}},
        {"Example 3", {5, 4, 3, 2, 1}, {5, 4, 3, 2, 1}},
        {"Empty list", {}, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        ListNode *got = remove_nodes(build_list(tt.head));
        t::check("remove_nodes()", list_values(got), tt.want);
    }
    return t::done();
}
