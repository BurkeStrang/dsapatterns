namespace DsaPatterns.TopKElements;

// Given a sorted number array and two integers ‘K’ and ‘X’,
// find ‘K’ closest numbers to ‘X’ in the array.
// Return the numbers in the sorted order.
// ‘X’ is not necessarily present in the array.
//
// Example 1:
// Input: [5, 6, 7, 8, 9], K = 3, X = 7
// Output: [6, 7, 8]
//
// Example 2:
// Input: [2, 4, 5, 6, 9], K = 3, X = 6
// Output: [4, 5, 6]
//
// Example 3:
// Input: [2, 4, 5, 6, 9], K = 3, X = 10
// Output: [5, 6, 9]

internal static class KClosestNumbers
{
    internal static List<int> FindClosestElements(int[] arr, int k, int x)
    {
        int index = BinarySearch(arr, x);
        int low = index - k;
        int high = index + k;
        low = Math.Max(low, 0); // 'low' should not be less than zero
        // 'high' should not be greater the size of the array
        high = Math.Min(high, arr.Length - 1);

        // min heap of indexes, ordered by absolute difference from 'X'
        PriorityQueue<int, int> minHeap = new();
        // add all candidate elements to the min heap, sorted by their absolute
        // difference from 'X'
        for (int i = low; i <= high; i++)
        {
            minHeap.Enqueue(i, Math.Abs(arr[i] - x));
        }

        // we need the top 'K' elements having the smallest difference from 'X'
        List<int> result = [];
        for (int n = 0; n < k; n++)
        {
            result.Add(arr[minHeap.Dequeue()]);
        }

        result.Sort();
        return result;
    }

    private static int BinarySearch(int[] arr, int target)
    {
        int low = 0;
        int high = arr.Length - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            if (arr[mid] == target)
            {
                return mid;
            }

            if (arr[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (low > 0)
        {
            return low - 1;
        }

        return low;
    }
}
