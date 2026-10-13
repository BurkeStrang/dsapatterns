namespace DsaPatterns.TwoPointers;

// Given an array containing 0s, 1s and 2s, sort the array in-place.
// You should treat numbers of the array as objects, hence, we can’t count 0s,
// 1s, and 2s to recreate the array.
//
// The flag of the Netherlands consists of three colors: red, white and blue;
// and since our input array also consists of three different numbers that is
// why it is called Dutch National Flag problem.
//
// Examples
// Example 1
// Input: arr = [1, 0, 2, 1, 0]
// Output: [0, 0, 1, 1, 2]
// Explanation:
// All 0s are moved to the front, 1s in the middle, and 2s at the end.
// The relative order within each group doesn't matter.
// Example 2
// Input: arr= [2, 2, 0, 1, 2, 0]
// Output: [0, 0, 1, 2, 2, 2]
// Explanation:
// All 0s come first, followed by the 1, and then all 2s at the end.
// Sorting is done in-place without using extra space or counting.
// Constraints:
//
// n == arr.length
// 1 <= n <= 300
// arr[i] is either 0, 1, or 2.

internal static class DutchNationalFlag
{
    internal static int[] Dutch(int[] arr)
    {
        int zeros = 0;
        int twos = arr.Length - 1;
        int i = 0;
        while (i <= twos)
        {
            switch (arr[i])
            {
                case 0:
                    arr[i] = arr[zeros];
                    arr[zeros] = 0;
                    i++;
                    zeros++;
                    break;
                case 2:
                    arr[i] = arr[twos];
                    arr[twos] = 2;
                    // decrement 'twos' only, after the swap the number at
                    // index 'i' could be 0, 1, or 2
                    twos--;
                    break;
                case 1:
                    i++;
                    break;
                default:
                    throw new ArgumentException(
                        "Invalid Integer Must be 0,1,2"
                    );
            }
        }

        return arr;
    }
}
