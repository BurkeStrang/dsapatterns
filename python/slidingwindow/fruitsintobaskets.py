"""
You are visiting a farm to collect fruits.
The farm has a single row of fruit trees.
You will be given two baskets, and your goal is to pick as many fruits as
possible to be placed in the given baskets.

You will be given an array of characters where each character represents a
fruit tree.
The farm has following restrictions:

Each basket can have only one type of fruit. There is no limit to how many
fruit a basket can hold.
You can start with any tree, but you can’t skip a tree once you have started.
You will pick exactly one fruit from every tree until you cannot, i.e.,
you will stop when you have to pick from a third fruit type.
Write a function to return the maximum number of fruits in both baskets.

Example 1:

Input: arr=['A', 'B', 'C', 'A', 'C']
Output: 3
Explanation: We can put 2 'C' in one basket and one 'A' in the other from the
subarray ['C', 'A', 'C']
Example 2:

Input: arr = ['A', 'B', 'C', 'B', 'B', 'C']
Output: 5
Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
This can be done if we start with the second letter: ['B', 'C', 'B', 'B',
'C']
Constraints:

1 <= arr.length <=
0 <= arr[i] < arr.length
"""

from collections import defaultdict


def max_fruit(arr: list[str]) -> int:
    window_start = 0
    max_length = 0
    fruit_frequency_map: defaultdict[str, int] = defaultdict(int)
    # try to extend the range [window_start, window_end]
    for window_end in range(len(arr)):
        fruit_frequency_map[arr[window_end]] += 1
        # shrink the sliding window, until we're left with '2' fruits in the
        # frequency map
        while len(fruit_frequency_map) > 2:
            left_fruit = arr[window_start]
            fruit_frequency_map[left_fruit] -= 1
            if fruit_frequency_map[left_fruit] == 0:
                del fruit_frequency_map[left_fruit]
            window_start += 1  # shrink the window
        max_length = max(max_length, window_end - window_start + 1)
    return max_length
