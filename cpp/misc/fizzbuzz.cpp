#include <string>
#include <vector>

// Given a number n, return the numbers from 1 to n as strings, but with
// "Fizz" for the multiples of 3, "Buzz" for the multiples of 5, and
// "FizzBuzz" for the multiples of both.

std::vector<std::string> fizz_buzz(int n)
{
    std::vector<std::string> res;
    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
        {
            res.push_back("FizzBuzz");
        }
        else if (i % 5 == 0)
        {
            res.push_back("Buzz");
        }
        else if (i % 3 == 0)
        {
            res.push_back("Fizz");
        }
        else
        {
            res.push_back(std::to_string(i));
        }
    }
    return res;
}
