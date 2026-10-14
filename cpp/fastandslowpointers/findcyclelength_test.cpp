#include "findcyclelength.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> values;
        int cycle_start; // the index the last node points back to, or -1
        int want;
    };
    std::vector<test> tests = {
        // cycle starts at the second node, length 3
        {"cycle of length 3", {1, 2, 3, 4}, 1, 3},
        {"no cycle", {1, 2, 3}, -1, 0},
        {"cycle of length 1 (self loop)", {1}, 0, 1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<ListNode *> nodes = build_nodes(tt.values);
        if (tt.cycle_start >= 0)
        {
            nodes.back()->next = nodes[tt.cycle_start];
        }
        t::check("find_cycle_length()", find_cycle_length(nodes[0]), tt.want);
    }
    return t::done();
}
