"""
Given a binary tree where each node can only have a digit (0-9) value,
each root-to-leaf path will represent a number.
Find the total sum of all the numbers represented by all paths.
"""

from common.tree import TreeNode


def find_path_sum(node: TreeNode | None, current_sum: int) -> int:
    if node is None:
        return 0

    # calculate the path number for the current node
    current_sum = current_sum * 10 + node.value

    # if it's a leaf node, return the current path sum
    if node.left is None and node.right is None:
        return current_sum

    # traverse left and right subtrees
    return find_path_sum(node.left, current_sum) + find_path_sum(
        node.right, current_sum
    )


def find_sum_of_path_numbers(root: TreeNode | None) -> int:
    return find_path_sum(root, 0)
