#include "startofcycle.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> values;
        int cycle_start; // the index the last node points back to, or -1
    };
    std::vector<test> tests = {
        {"cycle at node 2", {1, 2, 3, 4}, 1},
        {"cycle at the head", {1, 2, 3}, 0},
        {"no cycle", {1, 2, 3}, -1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<ListNode *> nodes = build_nodes(tt.values);
        ListNode *want = nullptr;
        if (tt.cycle_start >= 0)
        {
            want = nodes[tt.cycle_start];
            nodes.back()->next = want;
        }
        ListNode *got = find_cycle_start(nodes[0]);
        if (got != want)
        {
            t::errorf("find_cycle_start() = node {}, want node {}",
                      got == nullptr ? "null" : std::to_string(got->value),
                      want == nullptr ? "null" : std::to_string(want->value));
        }
    }
    return t::done();
}
