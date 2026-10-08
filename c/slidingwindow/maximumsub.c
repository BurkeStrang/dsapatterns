// Given an array of positive numbers and a positive number 'k,' find the
// maximum sum of any contiguous subarray of size 'k'.
//
// Example 1:
//
// Input: arr = [2, 1, 5, 1, 3, 2], k=3
// Output: 9
// Explanation: Subarray with maximum sum is [5, 1, 3].
// Example 2:
//
// Input: arr = [2, 3, 4, 1, 5], k=2
// Output: 7
// Explanation: Subarray with maximum sum is [3, 4].

int find_max_sum_sub_array
(
    int k,
    const int *arr,
    int arr_len
)
{
    int window_sum = 0;
    int max_sum = 0;
    int window_start = 0;
    for (int window_end = 0; window_end < arr_len; window_end++)
    {
        window_sum += arr[window_end]; // add the next element
        // slide the window, no need to slide if we've not hit the window size
        // of 'k'
        if (window_end >= k - 1)
        {
            if (window_sum > max_sum)
            {
                max_sum = window_sum;
            }
            window_sum -= arr[window_start]; // subtract the element going out
            window_start++;                  // slide the window ahead
        }
    }
    return max_sum;
}
