namespace DsaPatterns.BitwiseXor;

// In a non-empty array of integers,
// every number appears twice except for one,
// find that single number. Use 0(1) space
// and O(n) time complexity. You can
// modify the input array.
//
// Example 1:
// Input: 1, 4, 2, 1, 3, 2, 3
// Output: 4
//
// Example 2:
// Input: 7, 9, 7
// Output: 9

internal static class SingleNumber
{
    internal static int FindSingleNumber(int[] arr)
    {
        int num = 0; // Initialize a variable to store the result
        for (int i = 0; i < arr.Length; i++)
        {
            num ^= arr[i]; // XOR operation to find the single number
        }

        return num;
    }
}
