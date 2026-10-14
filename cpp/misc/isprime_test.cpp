#include "isprime.cpp"

#include "testing/testing.hpp"

#include <string>
#include <utility>

int main()
{
    t::run("is_prime");
    std::vector<std::pair<int, bool>> is_prime_tests = {
        {1, false}, {2, true}, {3, true}, {4, false}, {5, true}, {167, true},
    };
    for (auto [n, want] : is_prime_tests)
    {
        t::check("is_prime(" + std::to_string(n) + ")", is_prime(n), want);
    }

    t::run("count_primes");
    std::vector<std::pair<int, int>> count_primes_tests = {
        {1, 0}, {10, 4}, {100, 25}, {1000, 168}, {10000, 1229},
    };
    for (auto [n, want] : count_primes_tests)
    {
        t::check("count_primes(" + std::to_string(n) + ")", count_primes(n),
                 want);
    }

    t::run("get_primes");
    std::vector<std::pair<int, std::vector<int>>> get_primes_tests = {
        {1, {}},
        {10, {2, 3, 5, 7}},
        {20, {2, 3, 5, 7, 11, 13, 17, 19}},
        {30, {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}},
        {100, {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
               43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}},
    };
    for (const auto &[n, want] : get_primes_tests)
    {
        t::check("get_primes(" + std::to_string(n) + ")", get_primes(n), want);
    }
    return t::done();
}
