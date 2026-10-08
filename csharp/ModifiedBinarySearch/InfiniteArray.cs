namespace DsaPatterns.ModifiedBinarySearch;

// Given an infinite sorted array (or an array with unknown size),
// find if a given number ‘key’ is present in the array.
// Write a function to return the index of the ‘key’ if it is present in the
// array, otherwise return -1.
// Since it is not possible to define an array with infinite (unknown) size,
// you will be provided with an interface ArrayReader to read elements of the
// array.
// ArrayReader.get(index) will return the number at index;
// if the array’s size is smaller than the index, it will return
// Integer.MAX_VALUE.
//
// Example 1:
// Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
// Output: 6
// Explanation: The key is present at index '6' in the array.
//
// Example 2:
// Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 11
// Output: -1
// Explanation: The key is not present in the array.
//
// Example 3:
// Input: [1, 3, 8, 10, 15], key = 15
// Output: 4
// Explanation: The key is present at index '4' in the array.
//
// Example 4:
// Input: [1, 3, 8, 10, 15], key = 200
// Output: -1
// Explanation: The key is not present in the array.

internal class ArrayReader(int[] arr)
{
    public int Get(int index)
    {
        if (index >= arr.Length)
        {
            return int.MaxValue;
        }

        return arr[index];
    }
}

internal static class InfiniteArray
{
    internal static int SearchInfiniteSortedArray(ArrayReader reader, int key)
    {
        // find the proper bounds first
        int start = 0;
        int end = 1;
        while (reader.Get(end) < key)
        {
            int newStart = end + 1;
            end += (end - start + 1) * 2; // increase to double the bounds size
            start = newStart;
        }

        return BinarySearch(reader, key, start, end);
    }

    private static int BinarySearch(
        ArrayReader reader,
        int key,
        int start,
        int end
    )
    {
        while (start <= end)
        {
            int mid = start + ((end - start) / 2);
            if (key < reader.Get(mid))
            {
                end = mid - 1;
            }
            else if (key > reader.Get(mid))
            {
                start = mid + 1;
            }
            else // found the key
            {
                return mid;
            }
        }

        return -1;
    }
}
