#include <cctype>
#include <string>
#include <vector>

// Given an expression containing digits and operations (+, -, *),
// find all possible ways in which the expression can be evaluated
// by grouping the numbers and operators using parentheses.
//
// Example 1:
// Input: "1+2*3"
// Output: 7, 9
// Explanation:
//   1+(2*3) => 7
//   (1+2)*3 => 9
//
// Example 2:
// Input: "2*3-4-5"
// Output: 8, -12, 7, -7, -3
// Explanation:
//   2*(3-(4-5)) => 8
//   2*(3-4-5) => -12
//   2*3-(4-5) => 7
//   2*(3-4)-5 => -7
//   (2*3)-4-5 => -3

std::vector<int> diff_ways_to_evaluate_expression(const std::string &input)
{
    std::vector<int> result;

    // base case: if the input string is a number, parse and add it to output.
    if (input.find_first_of("+-*") == std::string::npos)
    {
        result.push_back(std::stoi(input));
        return result;
    }

    for (std::size_t i = 0; i < input.size(); i++)
    {
        char chr = input[i];
        if (std::isdigit(static_cast<unsigned char>(chr)))
        {
            continue;
        }
        // break the equation here into two parts and make recursively calls
        std::vector<int> left_parts =
            diff_ways_to_evaluate_expression(input.substr(0, i));
        std::vector<int> right_parts =
            diff_ways_to_evaluate_expression(input.substr(i + 1));
        for (int part1 : left_parts)
        {
            for (int part2 : right_parts)
            {
                if (chr == '+')
                {
                    result.push_back(part1 + part2);
                }
                else if (chr == '-')
                {
                    result.push_back(part1 - part2);
                }
                else if (chr == '*')
                {
                    result.push_back(part1 * part2);
                }
            }
        }
    }

    return result;
}
