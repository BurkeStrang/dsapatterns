namespace DsaPatterns.PrefixSum;

// Given an input array of integers nums,
// find an integer array,
// let's call it differenceArray,
// of the same length as an input integer array.
// Each element of differenceArray, i.e.,
// differenceArray[i],
// should be calculated as follows: take the sum
// of all elements to the left of index i in array nums
// (let's call it leftSumi), and subtract it from
// the sum of all elements to the right of index i in array nums
// (let's call it rightSumi), taking the absolute value of the result:
// differenceArray[i] = | leftSumi - rightSumi |
// If there are no elements to the left or right of i,
// the corresponding sum should be taken as 0.
//
// Example 1:
// Input: nums = [2, 5, 1, 6, 1]
// Expected Output: [13, 6, 0, 7, 14]
// Explanation:
// For i=0: |(0) - (5+1+6+1)| = |0 - 13| = 13
// For i=1: |(2) - (1+6+1)| = |2 - 8| = 6
// For i=2: |(2+5) - (6+1)| = |7 - 7| = 0
// For i=3: |(2+5+1) - (1)| = |8 - 1| = 7
// For i=4: |(2+5+1+6) - (0)| = |14 - 0| = 14
//
// Example 2:
// Input: nums = [3, 3, 3]
// Expected Output: [6, 0, 6]
// Explanation:
// For i=0: |(0) - (3+3)| = 6
// For i=1: |(3) - (3)| = 0
// For i=2: |(3+3) - (0)| = 6
//
// Example 3:
// Input: nums = [1, 2, 3, 4, 5]
// Expected Output: [14, 11, 6, 1, 10]
// Explanation:
// Calculations for each index i will follow the above-mentioned logic.
//
// Constraints:
// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 105

internal static class LeftAndRightSumDiff
{
    internal static int[] Find(int[] nums)
    {
        int n = nums.Length;
        int[] differenceArray = new int[n];
        int rightSum = nums.Sum();
        int leftSum = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            rightSum -= nums[i];
            int indexSum = Math.Abs(leftSum - rightSum);
            differenceArray[i] = indexSum;
            leftSum += nums[i];
        }
        return differenceArray;
    }
}
