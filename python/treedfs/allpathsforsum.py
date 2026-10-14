"""
Given a binary tree and a number ‘S’,
find all paths from root-to-leaf such that the sum of all the node values of
each path equals ‘S’.

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
"""

from common.tree import TreeNode


def find_paths_recursive(
    current_node: TreeNode | None,
    target: int,
    current_path: list[int],
    all_paths: list[list[int]],
) -> None:
    if current_node is None:
        return

    # add the current node to the path
    current_path.append(current_node.value)

    if (
        current_node.value == target
        and current_node.left is None
        and current_node.right is None
    ):
        # if the current node is a leaf and its value is equal to target, save
        # a copy of the current path
        all_paths.append(list(current_path))
    else:
        # traverse the left sub-tree
        find_paths_recursive(
            current_node.left,
            target - current_node.value,
            current_path,
            all_paths,
        )
        # traverse the right sub-tree
        find_paths_recursive(
            current_node.right,
            target - current_node.value,
            current_path,
            all_paths,
        )

    # remove the current node from the path to backtrack, we need to remove
    # the current node while we are going up the recursive call stack
    current_path.pop()


def find_paths(root: TreeNode | None, target: int) -> list[list[int]]:
    all_paths: list[list[int]] = []
    find_paths_recursive(root, target, [], all_paths)
    return all_paths
