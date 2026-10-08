namespace DsaPatterns.TwoPointers;

// Given an array of unsorted numbers and a target number,
// find all unique quadruplets in it, whose sum is equal to the target number.
//
// Example 1:
//
// Input: [4, 1, 2, -1, 1, -3], target=1
// Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Example 2:
//
// Input: [2, 0, -1, 1, -2, 2], target=2
// Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
// Explanation: Both the quadruplets add up to the target.
// Constraints:
//
// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

internal static class QuadrupleSumToTarget
{
    internal static List<List<int>> SearchQuadruplets(int[] arr, int target)
    {
        Array.Sort(arr);
        List<List<int>> quadruplets = [];
        for (int i = 0; i < arr.Length - 3; i++)
        {
            // skip same element to avoid duplicate quadruplets
            if (i > 0 && arr[i] == arr[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < arr.Length - 2; j++)
            {
                // skip same element to avoid duplicate quadruplets
                if (j > i + 1 && arr[j] == arr[j - 1])
                {
                    continue;
                }

                SearchPairs(arr, target, i, j, quadruplets);
            }
        }

        return quadruplets;
    }

    private static void SearchPairs(
        int[] arr,
        int targetSum,
        int first,
        int second,
        List<List<int>> quadruplets
    )
    {
        int left = second + 1;
        int right = arr.Length - 1;
        while (left < right)
        {
            int sum = arr[first] + arr[second] + arr[left] + arr[right];
            if (sum == targetSum) // found the quadruplet
            {
                quadruplets.Add([
                    arr[first],
                    arr[second],
                    arr[left],
                    arr[right],
                ]);
                left++;
                right--;
                while (left < right && arr[left] == arr[left - 1])
                {
                    left++; // skip same element to avoid duplicates
                }

                while (left < right && arr[right] == arr[right + 1])
                {
                    right--; // skip same element to avoid duplicates
                }
            }
            else if (sum < targetSum)
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
