#include "redundantconnection.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::array<int, 2>> edges;
        std::optional<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1",
         {{1, 2}, {1, 3}, {3, 4}, {1, 4}, {1, 5}},
         std::vector<int>{1, 4}},
        {"Example 2", {{1, 2}, {2, 3}, {3, 1}, {3, 4}}, std::vector<int>{3, 1}},
        {"Example 3",
         {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {5, 6}},
         std::vector<int>{4, 2}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_redundant_connection()",
                 find_redundant_connection(tt.edges), tt.want);
    }
    return t::done();
}
