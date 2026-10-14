#include "knapsack01.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> profits;
        std::vector<int> weights;
        int capacity;
        int want;
    };
    std::vector<test> tests = {
        {"Example", {4, 5, 3, 7}, {2, 3, 1, 4}, 5, 10},
        {"Second example", {1, 6, 10, 16}, {1, 2, 3, 5}, 7, 22},
        {"Nothing fits", {4, 5}, {3, 4}, 2, 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("solve_knapsack()",
                 solve_knapsack(tt.profits, tt.weights, tt.capacity), tt.want);
    }
    return t::done();
}
