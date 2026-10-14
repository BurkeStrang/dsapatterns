"""
Given a binary tree,Given a binary tree, populate an array to represent its
level-by-level traversal.
You should populate the values of all nodes of each level from left to right
in separate sub-arrays.
populate an array to represent its level-by-level traversal.
You should populate the values of all nodes of each level from left to right
in separate sub-arrays.
"""

from collections import deque

from common.tree import TreeNode


def traverse_basic(root: TreeNode | None) -> list[list[int]]:
    result: list[list[int]] = []
    if root is None:
        return result

    queue = deque([root])
    while queue:
        current_level: list[int] = []
        for _ in range(len(queue)):
            current_node = queue.popleft()
            # add the node to the current level
            current_level.append(current_node.value)
            # insert the children of current node in the queue
            if current_node.left is not None:
                queue.append(current_node.left)
            if current_node.right is not None:
                queue.append(current_node.right)
        result.append(current_level)

    return result
