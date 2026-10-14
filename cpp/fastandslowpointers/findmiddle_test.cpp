#include "findmiddle.cpp"

#include "testing/testing.hpp"

#include <optional>

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> head;
        std::optional<int> want; // the value of the middle node
    };
    std::vector<test> tests = {
        {"odd length list", {1, 2, 3, 4, 5}, 3},
        {"even length list", {1, 2, 3, 4}, 3},
        {"single node", {1}, 1},
        {"two nodes", {1, 2}, 2},
        {"empty list", {}, std::nullopt},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        ListNode *middle = find_middle(build_list(tt.head));
        std::optional<int> got;
        if (middle != nullptr)
        {
            got = middle->value;
        }
        t::check("find_middle()", got, tt.want);
    }
    return t::done();
}
