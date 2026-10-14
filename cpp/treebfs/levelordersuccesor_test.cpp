#include "levelordersuccesor.cpp"

#include "testing/testing.hpp"

#include <optional>

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        int key;
        std::optional<int> want; // the value of the successor
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 2, 3, 4, 5]", 3, 4},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]", 9, 10},
        {"Example 3", "[12, 7, 1, 9, null, 10, 5]", 12, 7},
        {"No successor (last node)", "[1, 2]", 2, std::nullopt},
        {"Empty tree", "[]", 1, std::nullopt},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        TreeNode *successor = find_successor(tree(tt.root), tt.key);
        std::optional<int> got;
        if (successor != nullptr)
        {
            got = successor->value;
        }
        t::check("find_successor()", got, tt.want);
    }
    return t::done();
}
