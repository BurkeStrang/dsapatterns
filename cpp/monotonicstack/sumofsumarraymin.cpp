#include <vector>

// Given an array of integers arr, return the sum of the minimum values from all
// possible contiguous subarrays within arr.
// Since the result can be very large, return the final sum modulo (109 + 7).
//
// Example 1:
// Input: arr = [3, 1, 2, 4, 5]
// Expected Output: 30
// Explanation:
// The subarrays are: [3], [1], [2], [4], [5], [3,1], [1,2], [2,4], [4,5],
// [3,1,2], [1,2,4], [2,4,5], [3,1,2,4], [1, 2, 4, 5], [3, 1, 2, 4, 5].
// The minimum values of these subarrays are: 3, 1, 2, 4, 5, 1, 1, 2, 4, 1, 1,
// 2, 1, 1, 1.
// Summing these minimums: 3 + 1 + 2 + 4 + 5 + 1 + 1 + 2 + 4 + 1 + 1 + 2 + 1 + 1
// + 1 = 30.
//
// Example 2:
// Input: arr = [2, 6, 5, 4]
// Expected Output: 36
// Explanation:
// The subarrays are: [2], [6], [5], [4], [2,6], [6,5], [5,4], [2,6,5], [6,5,4],
// [2,6,5,4].
// The minimum values of these subarrays are: 2, 6, 5, 4, 2, 5, 4, 2, 4, 2.
// Summing these minimums: 2 + 6 + 5 + 4 + 2 + 5 + 4 + 2 + 4 + 2 = 36.
//
// Example 3:
// Input: arr = [7, 3, 8]
// Expected Output: 35
// Explanation:
// The subarrays are: [7], [3], [8], [7,3], [3,8], [7,3,8].
// The minimum values of these subarrays are: 7, 3, 8, 3, 3, 3.
// Summing these minimums: 7 + 3 + 8 + 3 + 3 + 3 = 27.
//
// Constraints:
// 1 <= arr.length <= 3 * 104
// 1 <= arr[i] <= 3 * 104

long long sum_subarray_mins(const std::vector<int> &arr)
{
    constexpr long long mod = 1'000'000'007;
    int n = std::ssize(arr);
    long long result = 0; // Final sum of subarray minimums
    std::vector<int> stack;

    // Iterate through the array plus one extra iteration for a sentinel.
    for (int current_index = 0; current_index <= n; current_index++)
    {
        // If we reached the end, use 0 as a sentinel value; otherwise, use
        // the current element. It helps to process all remaining elements in
        // the stack.
        int current_element = current_index < n ? arr[current_index] : 0;

        // Process elements in the stack while the current element is smaller
        // than the element at the top. Here, we maintain monotonic increasing
        // stack.
        while (!stack.empty() && arr[stack.back()] > current_element)
        {
            // Pop the index whose corresponding element is greater than
            // current_element.
            int min_index = stack.back();
            stack.pop_back();

            // Calculate the number of subarrays where arr[min_index] is the
            // minimum:
            // 'ending' is the count of subarrays ending at min_index; they can
            // start anywhere after the previous index on the stack, or from
            // the start of the array if the stack is empty,
            // and 'starting' is the count of subarrays starting at min_index
            // that can extend until current_index.
            long long ending =
                stack.empty() ? min_index + 1 : min_index - stack.back();
            long long starting = current_index - min_index;
            long long count_subarrays = ending * starting;

            // Add the contribution of arr[min_index] for these subarrays to
            // the result.
            long long min = arr[min_index];
            result = (result + (min * count_subarrays) % mod) % mod;
        }

        // Push the current index onto the stack for further processing.
        stack.push_back(current_index);
    }

    return result;
}
