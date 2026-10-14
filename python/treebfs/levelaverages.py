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


def level_average(root: TreeNode | None) -> list[float]:
    result: list[float] = []
    if root is None:
        return result

    queue = deque([root])
    while queue:
        level_size = len(queue)
        level_sum = 0
        for _ in range(level_size):
            current_node = queue.popleft()
            # add the node's value to the running sum
            level_sum += current_node.value
            # insert the children of current node to the queue
            if current_node.left is not None:
                queue.append(current_node.left)
            if current_node.right is not None:
                queue.append(current_node.right)

        # append the current level's average to the result array
        result.append(level_sum / level_size)

    return result
