#include "common/list.h"

#include <ctype.h>
#include <stdbool.h>

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

// evaluate_range does the work for the first len characters of input.
IntList evaluate_range
(
    const char *input,
    int len
)
{
    IntList result = {0};
    // base case: if the input string is a number, parse and add it to output.
    bool is_number = true;
    for (int i = 0; i < len; i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*')
        {
            is_number = false;
        }
    }
    if (is_number)
    {
        int num = 0;
        for (int i = 0; i < len; i++)
        {
            num = num * 10 + (input[i] - '0');
        }
        intlist_push(&result, num);
        return result;
    }

    for (int i = 0; i < len; i++)
    {
        char chr = input[i];
        if (!isdigit((unsigned char)chr))
        {
            // break the equation here into two parts and make recursively
            // calls
            IntList left_parts = evaluate_range(input, i);
            IntList right_parts = evaluate_range(input + i + 1, len - i - 1);
            for (int l = 0; l < left_parts.len; l++)
            {
                for (int r = 0; r < right_parts.len; r++)
                {
                    int part1 = left_parts.items[l];
                    int part2 = right_parts.items[r];
                    switch (chr)
                    {
                    case '+':
                        intlist_push(&result, part1 + part2);
                        break;
                    case '-':
                        intlist_push(&result, part1 - part2);
                        break;
                    case '*':
                        intlist_push(&result, part1 * part2);
                        break;
                    }
                }
            }
            intlist_free(&left_parts);
            intlist_free(&right_parts);
        }
    }
    return result;
}

// The results are returned in a list that the caller must free.
IntList diff_ways_to_evaluate_expression
(
    const char *input
)
{
    return evaluate_range(input, (int)strlen(input));
}
