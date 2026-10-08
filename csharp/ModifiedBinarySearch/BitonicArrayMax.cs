namespace DsaPatterns.ModifiedBinarySearch;

// Find the maximum value in a given Bitonic array.
// An array is considered bitonic if it is first monotonically increasing and
// then monotonically decreasing.
// In other words, a bitonic array starts with a sequence of increasing
// elements, reaches a peak element, and then follows with a sequence of
// decreasing elements. The peak element is the maximum value in the array.
//
// Example 1:
// Input: [1, 3, 8, 12, 4, 2]
// Output: 12
// Explanation: The maximum number in the input bitonic array is '12'.
//
// Example 2:
// Input: [3, 8, 3, 1]
// Output: 8
//
// Example 3:
// Input: [1, 3, 8, 12]
// Output: 12
//
// Example 4:
// Input: [10, 9, 8]
// Output: 10

internal static class BitonicArrayMax
{
    internal static int FindMaxInBitonicArray(int[] arr)
    {
        int left = 0;
        int right = arr.Length - 1;

        while (left < right)
        {
            // left = 0, right = 2, mid = 1, arr[mid] = 9, arr[mid+1] = 8
            // left = 0, right = 1, mid = 0, arr[mid] = 10, arr[mid+1] = 9
            // left = 0, right = 0
            int mid = left + ((right - left) / 2);

            if (arr[mid] > arr[mid + 1])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }

        return arr[left];
    }
}
