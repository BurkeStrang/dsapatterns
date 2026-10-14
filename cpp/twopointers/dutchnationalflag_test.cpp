#include "dutchnationalflag.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"example1", {1, 0, 2, 1, 0}, {0, 0, 1, 1, 2}},
        {"example2", {2, 2, 0, 1, 2, 0}, {0, 0, 1, 2, 2, 2}},
        {"all zeros", {0, 0, 0}, {0, 0, 0}},
        {"all twos", {2, 2, 2}, {2, 2, 2}},
        {"already sorted", {0, 0, 1, 1, 2, 2}, {0, 0, 1, 1, 2, 2}},
        {"single element", {1}, {1}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        dutch(tt.arr);
        t::check("dutch()", tt.arr, tt.want);
    }
    return t::done();
}
