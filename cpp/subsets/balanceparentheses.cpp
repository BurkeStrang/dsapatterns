#include <queue>
#include <string>
#include <vector>

// For a given number 'num', write a function to generate all combinations of
// 'num' pairs of balanced parentheses.
//
// Example 1:
// Input: num=2
// Output: (()), ()()
//
// Example 2:
// Input: num=3
// Output: ((())), (()()), (())(), ()(()), ()()()

struct ParenthesesString
{
    std::string str;
    int open_count;  // open parentheses count
    int close_count; // close parentheses count
};

std::vector<std::string> generate_valid_parentheses(int num)
{
    std::vector<std::string> result;
    std::queue<ParenthesesString> queue;
    queue.push({"", 0, 0});

    while (!queue.empty())
    {
        ParenthesesString ps = queue.front();
        queue.pop();
        // if we've reached the maximum number of open and close parentheses,
        // add to result
        if (ps.open_count == num && ps.close_count == num)
        {
            result.push_back(ps.str);
        }
        else
        {
            // if we can add an open parentheses, add it
            if (ps.open_count < num)
            {
                queue.push({ps.str + "(", ps.open_count + 1, ps.close_count});
            }

            // if we can add a close parentheses, add it
            if (ps.open_count > ps.close_count)
            {
                queue.push({ps.str + ")", ps.open_count, ps.close_count + 1});
            }
        }
    }

    return result;
}
