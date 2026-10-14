"""
Example 1:
input: 2
output: 2
"""


def count_trees(n: int) -> int:
    if n <= 1:
        return 1
    count = 0
    for i in range(1, n + 1):
        # making 'i' root of the tree
        count_of_left_subtrees = count_trees(i - 1)
        count_of_right_subtrees = count_trees(n - i)
        count += count_of_left_subtrees * count_of_right_subtrees
    return count
