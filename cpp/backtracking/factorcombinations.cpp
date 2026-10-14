#include <vector>

// Numbers can be regarded as the product of their factors.
// For example, 8 = 2 x 2 x 2 = 2 x 4.
// Given an integer n,
// return all possible combinations of its factors.
// You may return the answer in any order.
//
// Example 1:
// Input: n = 8
// Output: [[2, 2, 2], [2, 4]]
//
// Example 2:
// Input: n = 20
// Output: [[2, 2, 5], [2, 10], [4, 5]]
//
// Constraints:
// 2 <= n <= 107

void get_all_factors(int n, int start, std::vector<int> &curr,
                     std::vector<std::vector<int>> &result)
{
    // go up to the square root of 'n'
    for (int i = start; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            curr.push_back(i);

            // 'i' and 'n / i' finish off a combination
            std::vector<int> curr_copy = curr;
            curr_copy.push_back(n / i);
            result.push_back(curr_copy);

            // keep 'i' and break 'n / i' down further
            get_all_factors(n / i, i, curr, result);
            curr.pop_back();
        }
    }
}

std::vector<std::vector<int>> get_factors(int n)
{
    std::vector<std::vector<int>> result;
    std::vector<int> curr;
    get_all_factors(n, 2, curr, result);
    return result;
}
