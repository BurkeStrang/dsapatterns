// Example 1:
// Input: ['a', 'c', 'f', 'h'], key = 'f'
// Output: 'h'

char search_next_letter
(
    const char *letters,
    int n,
    char key
)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (key < letters[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    // Since the loop is running until 'left <= right', so at the right of the
    // while loop, 'left == right+1'
    return letters[left % n];
}
