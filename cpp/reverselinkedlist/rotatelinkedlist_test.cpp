#include "rotatelinkedlist.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> head;
        int rotations;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"rotate by 2", {1, 2, 3, 4, 5}, 2, {4, 5, 1, 2, 3}},
        {"rotate by 0 (no change)", {1, 2, 3}, 0, {1, 2, 3}},
        {"rotate by length (no change)", {1, 2, 3}, 3, {1, 2, 3}},
        {"rotate by more than length", {1, 2, 3}, 5, {2, 3, 1}},
        {"single node", {1}, 1, {1}},
        {"empty list", {}, 3, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        ListNode *got = rotate(build_list(tt.head), tt.rotations);
        t::check("rotate()", list_values(got), tt.want);
    }
    return t::done();
}
