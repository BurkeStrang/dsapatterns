namespace DsaPatterns.ModifiedBinarySearch;

internal static class OrderAgnosticBs
{
    internal static int DescOrAscSearch(int[] arr, int key)
    {
        int left = 0;
        int right = arr.Length - 1;
        bool isAsc = arr[left] < arr[right];

        while (left <= right)
        {
            // calculate the middle of the current range
            int mid = left + ((right - left) / 2);

            if (key == arr[mid])
            {
                return mid;
            }

            if (isAsc) // ascending order
            {
                if (key < arr[mid])
                {
                    right = mid - 1; // the 'key' can be in the first half
                }
                else // key > arr[mid]
                {
                    left = mid + 1; // the 'key' can be in the second half
                }
            }
            else // descending order
            {
                if (key > arr[mid])
                {
                    right = mid - 1; // the 'key' can be in the first half
                }
                else // key < arr[mid]
                {
                    left = mid + 1; // the 'key' can be in the second half
                }
            }
        }

        return -1; // element not found
    }
}
