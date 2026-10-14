#include <vector>

// Example 1:
// Input: ['a', 'c', 'f', 'h'], key = 'f'
// Output: 'h'

char search_next_letter(const std::vector<char> &letters, char key)
{
    int n = std::ssize(letters);
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (key < letters[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    // since the loop is running until 'start <= end', so at the end of the
    // while loop, 'start == end+1'; if there is no bigger letter it is 'n',
    // which wraps around to the first letter
    return letters[start % n];
}
