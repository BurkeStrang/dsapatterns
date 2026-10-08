namespace DsaPatterns.SlidingWindow;

// Given an array of positive integers and a number ‘S,’ find the length of the
// smallest contiguous subarray whose sum is greater than or equal to 'S'.
// Return 0 if no such subarray exists.
//
// Example 1:
// Input: arr = [2, 1, 5, 2, 3, 2], S=7
// Output: 2
// Explanation: The smallest subarray with a sum greater than or equal to '7'
// is [5, 2].
//
// Example 2:
// Input: arr = [2, 1, 5, 2, 8], S=7
// Output: 1
// Explanation: The smallest subarray with a sum greater than or equal to '7'
// is [8].
//
// Example 3:
// Input: arr = [3, 4, 1, 1, 6], S=8
// Output: 3
// Explanation: Smallest subarrays with a sum greater than or equal to '8' are
// [3, 4, 1] or [1, 1, 6].
// Constraints:
//
// 1 <= S <=
// 1 <= arr.length <= 105
// 1 <= arr[i] <= 104

internal static class SmallestArrayGreatestSum
{
    internal static int FindMinSubArray(int s, int[] arr)
    {
        int windowSum = 0;
        int minLength = int.MaxValue;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < arr.Length; windowEnd++)
        {
            windowSum += arr[windowEnd]; // add the next element
            // shrink the window as small as possible until the 'windowSum' is
            // smaller than 's'
            while (windowSum >= s)
            {
                minLength = Math.Min(minLength, windowEnd - windowStart + 1);
                windowSum -= arr[windowStart]; // subtract the element going out
                windowStart++; // slide the window ahead
            }
        }

        if (minLength == int.MaxValue)
        {
            return 0;
        }

        return minLength;
    }
}
