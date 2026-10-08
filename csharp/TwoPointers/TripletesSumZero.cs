namespace DsaPatterns.TwoPointers;

// Given an array of unsorted numbers, find all unique triplets in it that add
// up to zero.
//
// Examples
// Example 1
// Input: [-3, 0, 1, 2, -1, 1, -2]
// Output: [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]
// Explanation: There are four unique triplets whose sum is equal to zero.
// Example 2
// Input: [-5, 2, -1, -2, 3]
// Output: [[-5, 2, 3], [-2, -1, 3]]
// Explanation: There are two unique triplets whose sum is equal to zero.
// Constraints:
//
// 3 <= arr.length <= 3000
// -105 <= arr[i] <= 105

internal static class TripletesSumZero
{
    internal static List<List<int>> SearchTriplets(int[] arr)
    {
        Array.Sort(arr);
        List<List<int>> triplets = [];
        for (int i = 0; i < arr.Length - 2; i++)
        {
            // skip same element to avoid duplicate triplets
            if (i > 0 && arr[i] == arr[i - 1])
            {
                continue;
            }

            SearchPair(arr, -arr[i], i + 1, triplets);
        }

        return triplets;
    }

    private static void SearchPair(
        int[] arr,
        int targetSum,
        int left,
        List<List<int>> triplets
    )
    {
        int right = arr.Length - 1;
        while (left < right)
        {
            int currentSum = arr[left] + arr[right];
            if (currentSum == targetSum) // found the triplet
            {
                triplets.Add([-targetSum, arr[left], arr[right]]);
                left++;
                right--;
                while (left < right && arr[left] == arr[left - 1])
                {
                    left++; // skip same element to avoid duplicate triplets
                }

                while (left < right && arr[right] == arr[right + 1])
                {
                    right--; // skip same element to avoid duplicate triplets
                }
            }
            else if (targetSum > currentSum)
            {
                left++; // we need a pair with a bigger sum
            }
            else
            {
                right--; // we need a pair with a smaller sum
            }
        }
    }
}
