"""
Given a root of the binary tree, find the minimum depth of a binary tree.
The minimum depth is the number of nodes along the shortest path from the
root node to the nearest leaf node.

Example 1
Input: [1,2,3,4,5]
Output: 2

Example 2
Input: [1,2]
Output: 2

Example 3
Input: [1,2,3,4,5,6]
Output: 3

Example 4
Input: [1]
Output: 1

Constraints:
The number of nodes in the tree is in the range [0, 10^5].
-1000 <= Node.val <= 1000
"""

from collections import deque

from common.tree import TreeNode


def find_depth(root: TreeNode | None) -> int:
    if root is None:
        return 0

    queue = deque([root])
    minimum_tree_depth = 0
    while queue:
        minimum_tree_depth += 1
        for _ in range(len(queue)):
            current_node = queue.popleft()

            # check if this is a leaf node
            if current_node.left is None and current_node.right is None:
                return minimum_tree_depth

            # insert the children of current node in the queue
            if current_node.left is not None:
                queue.append(current_node.left)
            if current_node.right is not None:
                queue.append(current_node.right)

    return minimum_tree_depth
