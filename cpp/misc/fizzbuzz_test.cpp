#include "fizzbuzz.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int n;
        std::vector<std::string> want;
    };
    std::vector<test> tests = {
        {"5", 5, {"1", "2", "Fizz", "4", "Buzz"}},
        {"15",
         15,
         {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11",
          "Fizz", "13", "14", "FizzBuzz"}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("fizz_buzz()", fizz_buzz(tt.n), tt.want);
    }
    return t::done();
}
