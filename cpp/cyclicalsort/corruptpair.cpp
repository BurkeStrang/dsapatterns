#include <optional>
#include <utility>
#include <vector>

// We are given an unsorted array containing ‘n’ numbers taken from the range 1
// to ‘n’.
// The array originally contained all the numbers from 1 to ‘n’,
// but due to a data error,
// one of the numbers got duplicated which also resulted in one number going
// missing.
// Find both these numbers.
//
// Example 1:
// Input: [3, 1, 2, 5, 2]
// Output: [2, 4]
// Explanation: '2' is duplicated and '4' is missing.
//
// Example 2:
// Input: [3, 1, 2, 3, 6, 4]
// Output: [3, 5]
// Explanation: '3' is duplicated and '5' is missing.
// Constraints:
//
// 2 <= nums.length <=
// 1 <= nums[i] <=

// find_corrupt returns the duplicated number and the missing number.
std::optional<std::pair<int, int>> find_corrupt(std::vector<int> &nums)
{
    int i = 0;
    while (i < std::ssize(nums))
    {
        // If the current number is not in its correct position, swap it with
        // the number at its correct position.
        int j = nums[i] - 1;
        if (nums[i] != nums[j])
        {
            std::swap(nums[i], nums[j]);
        }
        else
        {
            i++;
        }
    }

    // Iterate through the array to find the first misplaced number.
    for (int k = 0; k < std::ssize(nums); k++)
    {
        if (nums[k] != k + 1)
        {
            return std::pair{nums[k], k + 1};
        }
    }

    // No number is out of place.
    return std::nullopt;
}
