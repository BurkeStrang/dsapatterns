// Given an array containing 0s and 1s, if you are allowed to replace no more
// than ‘k’ 0s with 1s,
// find the length of the longest contiguous subarray having all 1s.
//
// Example 1:
// Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
// Output: 6
// Explanation: Replace the '0' at index 5 and 8 to have the longest contiguous
// subarray of 1s having length 6.
//
// Example 2:
// Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
// Output: 9
// Explanation: Replace the '0' at index 6, 9, and 10 to have the longest
// contiguous subarray of 1s having length 9.
//
// Example 3:
// Input: Array=[1, 0, 0, 1, 1, 0, 1, 1], k=2
// Output: 6
// Explanation: By flipping 0 at the second and fifth index in the list, we get
// [1, 0, 1, 1, 1, 1, 1, 1], which has 6 consecutive 1s.
// Constraints:
//
// 1 <= arr.length <=
// arr[i] is either 0 or 1.
// 0 <= k <= nums.length

int max_ones_length
(
    const int *arr,
    int arr_len,
    int k
)
{
    int window_start = 0;
    int max_length = 0;
    int max_ones_count = 0;

    for (int window_end = 0; window_end < arr_len; window_end++)
    {
        if (arr[window_end] == 1)
        {
            max_ones_count++;
        }
        // current window size is from window_start to window_end, overall we
        // have a maximum of 1s repeating a maximum of 'max_ones_count' times,
        // this means that we can have a window with 'max_ones_count' 1s and
        // the remaining are 0s which should replace with 1s. Now, if the
        // remaining 0s are more than 'k', it is the time to shrink the window
        // as we are not allowed to replace more than 'k' Os.
        if (window_end - window_start + 1 - max_ones_count > k)
        {
            if (arr[window_start] == 1)
            {
                max_ones_count--;
            }
            window_start++;
        }
        if (window_end - window_start + 1 > max_length)
        {
            max_length = window_end - window_start + 1;
        }
    }
    return max_length;
}
