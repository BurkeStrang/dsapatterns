"""
Given a binary tree and a number sequence,
find if the sequence is present as a root-to-leaf path in the given tree.
"""

from common.tree import TreeNode


def find_path_recursive(
    current_node: TreeNode | None, sequence: list[int], sequence_index: int
) -> bool:
    if current_node is None:
        return False

    sequence_length = len(sequence)
    if (
        sequence_index >= sequence_length
        or current_node.value != sequence[sequence_index]
    ):
        return False

    # if the current node is a leaf, and it is the end of the sequence, we
    # have found a path!
    if (
        current_node.left is None
        and current_node.right is None
        and sequence_index == sequence_length - 1
    ):
        return True

    # recursively call to traverse the left and right sub-tree
    # return true if any of the two recursive call return true
    return find_path_recursive(
        current_node.left, sequence, sequence_index + 1
    ) or find_path_recursive(current_node.right, sequence, sequence_index + 1)


def find_path(root: TreeNode | None, sequence: list[int]) -> bool:
    if root is None:
        return len(sequence) == 0
    return find_path_recursive(root, sequence, 0)
