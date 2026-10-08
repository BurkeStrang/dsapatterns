// Given an array of sorted numbers, move all non-duplicate number instances at
// the beginning of the array in-place.
// The non-duplicate numbers should be sorted and you should not use any extra
// space so that the solution has constant space complexity i.e., O(1).
//
// Move all the unique number instances at the beginning of the array and after
// moving return the length of the subarray that has no duplicate in it.
//
// Example 1:
//
// Input: [2, 3, 3, 3, 6, 9, 9]
// Output: 4
// Explanation: The first four elements after moving element will be [2, 3, 6,
// 9].
// Example 2:
//
// Input: [2, 2, 2, 11]
// Output: 2
// Explanation: The first two elements after moving elements will be [2, 11].
// Constraints:
//
// 1 <= nums.length <= 3 * 104
// -100 <= nums[i] <= 100
// nums is sorted in non-decreasing order.

int move_elements
(
    int *arr,
    int arr_len
)
{
    // Initialize the pointer to the next non-duplicate element as 1.
    int next_non_duplicate = 1;
    // Iterate through the input array.
    for (int i = 1; i < arr_len; i++)
    {
        // Check if the element at the next_non_duplicate-1 position is not
        // equal to the current element.
        if (arr[next_non_duplicate - 1] != arr[i])
        {
            // If they are not equal, update the element at the
            // next_non_duplicate position with the current element.
            arr[next_non_duplicate] = arr[i];
            // Increment the next_non_duplicate pointer.
            next_non_duplicate++;
        }
    }
    // Return the length of the modified array without duplicates.
    return next_non_duplicate;
}
