"""
Example 1:
Input: ['a', 'c', 'f', 'h'], key = 'f'
Output: 'h'
"""


def search_next_letter(letters: list[str], key: str) -> str:
    n = len(letters)
    start = 0
    end = n - 1
    while start <= end:
        mid = start + (end - start) // 2
        if key < letters[mid]:
            end = mid - 1
        else:
            start = mid + 1

    # since the loop is running until 'start <= end', so at the end of the
    # while loop, 'start == end+1'; if there is no bigger letter it is 'n',
    # which wraps around to the first letter
    return letters[start % n]
