namespace DsaPatterns.ModifiedBinarySearch;

// Given a Bitonic array, find if a given ‘key’ is present in it.
// An array is considered bitonic if it is first monotonically increasing and
// then monotonically decreasing.
// In other words,
// a bitonic array starts with a sequence of increasing elements,
// reaches a peak element,
// and then follows with a sequence of decreasing elements.
// The peak element is the maximum value in the array.
// Write a function to return the index of the ‘key’.
// If the 'key' appears more than once, return the smaller index.
// If the ‘key’ is not present, return -1.
//
// Example 1:
// Input: [1, 3, 8, 4, 3], key=4
// Output: 3
//
// Example 2:
// Input: [3, 8, 3, 1], key=8
// Output: 1
//
// Example 3:
// Input: [1, 3, 8, 12], key=12
// Output: 3
//
// Example 4:
// Input: [10, 9, 8], key=10
// Output: 0

internal static class BitonicArray
{
    // SearchBitonic searches for a key in a bitonic array
    internal static int SearchBitonic(int[] arr, int key)
    {
        int maxIndex = FindMax(arr);
        int keyIndex = SearchWithin(arr, key, 0, maxIndex);
        if (keyIndex != -1)
        {
            return keyIndex;
        }

        return SearchWithin(arr, key, maxIndex + 1, arr.Length - 1);
    }

    private static int FindMax(int[] arr)
    {
        int start = 0;
        int end = arr.Length - 1;
        while (start < end)
        {
            int mid = start + ((end - start) / 2);
            if (arr[mid] > arr[mid + 1])
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        // at the end of the while loop, 'start == end'
        return start;
    }

    // SearchWithin is an order-agnostic binary search
    private static int SearchWithin(int[] arr, int key, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (key == arr[mid])
            {
                return mid;
            }

            if (arr[start] < arr[end]) // ascending order
            {
                if (key < arr[mid])
                {
                    end = mid - 1;
                }
                else // key > arr[mid]
                {
                    start = mid + 1;
                }
            }
            else // descending order
            {
                if (key > arr[mid])
                {
                    end = mid - 1;
                }
                else // key < arr[mid]
                {
                    start = mid + 1;
                }
            }
        }

        return -1; // element is not found
    }
}
