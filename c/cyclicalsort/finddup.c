// We are given an unsorted array containing n+1 numbers taken from the range 1
// to n.
// The array has only one duplicate but it can be repeated multiple times.
// Find that duplicate number without using any extra space.
// You are, however, allowed to modify the input array.
//
// Example 1:
// Input: [1, 4, 4, 3, 2]
// Output: 4
//
// Example 2:
// Input: [2, 1, 3, 3, 5, 4]
// Output: 3
//
// Example 3:
// Input: [2, 4, 1, 4, 4]
// Output: 4
// Constraints:
//
// nums.length == n + 1
// 1 <= n <=
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer
// which appears two or more times.

int find_start
(
    const int *arr,
    int cycle_length
)
{
    int pointer1 = arr[0];
    int pointer2 = arr[0];
    // Move pointer2 ahead 'cycle_length' steps
    for (int i = 0; i < cycle_length; i++)
    {
        pointer2 = arr[pointer2];
    }

    // Increment both pointers until they meet at the start of the cycle
    while (pointer1 != pointer2)
    {
        pointer1 = arr[pointer1];
        pointer2 = arr[pointer2];
    }

    return pointer1;
}

int find_dup
(
    const int *arr
)
{
    int slow = 0;
    int fast = 0;
    // Find the intersection point of the two runners.
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Find the cycle length
    int current = arr[slow];
    int cycle_length = 1;
    while (arr[current] != arr[slow])
    {
        current = arr[current];
        cycle_length++;
    }

    return find_start(arr, cycle_length);
}
