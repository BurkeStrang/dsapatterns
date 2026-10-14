#include "linkedlistcycle.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> values;
        int cycle_start; // the index the last node points back to, or -1
        bool want;
    };
    std::vector<test> tests = {
        {"no cycle", {1, 2, 3}, -1, false},
        {"cycle exists", {1, 2, 3}, 0, true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<ListNode *> nodes = build_nodes(tt.values);
        if (tt.cycle_start >= 0)
        {
            nodes.back()->next = nodes[tt.cycle_start];
        }
        t::check("has_cycle()", has_cycle(nodes[0]), tt.want);
    }
    return t::done();
}
