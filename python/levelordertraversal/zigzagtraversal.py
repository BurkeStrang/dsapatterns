"""
Example 1:
input: root = [3,9,20,null,null,15,7]
output: [[3],[20,9],[15,7]]
"""

from collections import deque

from common.tree import TreeNode


def traverse_zig_zag(root: TreeNode | None) -> list[list[int]]:
    result: list[list[int]] = []
    if root is None:
        return result

    queue = deque([root])
    left_to_right = True
    while queue:
        current_level: deque[int] = deque()
        for _ in range(len(queue)):
            current_node = queue.popleft()

            # add the node to the current level based on the traverse
            # direction
            if left_to_right:
                current_level.append(current_node.value)
            else:
                current_level.appendleft(current_node.value)

            # insert the children of current node in the queue
            if current_node.left is not None:
                queue.append(current_node.left)
            if current_node.right is not None:
                queue.append(current_node.right)

        result.append(list(current_level))
        # reverse the traversal direction
        left_to_right = not left_to_right

    return result
