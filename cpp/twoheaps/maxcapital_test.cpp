#include "maxcapital.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> capital;
        std::vector<int> profits;
        int number_of_projects;
        int initial_capital;
        int want;
    };
    std::vector<test> tests = {
        {"basic example", {0, 1, 2}, {1, 2, 3}, 2, 1, 6},
        {"not enough capital for any project", {5, 10, 15}, {1, 2, 3}, 3, 0, 0},
        {"all projects affordable from start", {0, 0, 0}, {1, 2, 3}, 2, 0, 5},
        {"single project", {0}, {5}, 1, 0, 5},
        {"chain of unlocking projects", {0, 1, 2, 3}, {1, 1, 1, 1}, 4, 0, 4},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_maximum_capital()",
                 find_maximum_capital(tt.capital, tt.profits,
                                      tt.number_of_projects,
                                      tt.initial_capital),
                 tt.want);
    }
    return t::done();
}
