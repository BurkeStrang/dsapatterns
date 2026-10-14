"""
Given a binary tree, find the length of its diameter.
The diameter of a tree is the number of nodes on the longest path between any
two leaf nodes.
The diameter of a tree may or may not pass through the root.
Note: You can always assume that there are at least two leaf nodes in the
given tree.

Constraints:
n == edges.length + 1
1 <= n <= 104
0 <= ai, bi < n
ai != bi
"""

from common.tree import TreeNode


def find_diameter(root: TreeNode | None) -> int:
    tree_diameter = 0

    def calculate_height(current_node: TreeNode | None) -> int:
        """Returns the height of current_node, and updates tree_diameter with
        the longest path through it."""
        nonlocal tree_diameter
        if current_node is None:
            return 0

        left_tree_height = calculate_height(current_node.left)
        right_tree_height = calculate_height(current_node.right)

        # if the current node doesn't have a left or right subtree, we can't
        # have a path passing through it, since we need a leaf node on each
        # side
        if left_tree_height != 0 and right_tree_height != 0:
            # diameter at the current node will be equal to the height of left
            # subtree + the height of right sub-trees + '1' for the current
            # node
            diameter = left_tree_height + right_tree_height + 1

            # update the global tree diameter
            tree_diameter = max(tree_diameter, diameter)

        # height of the current node will be equal to the maximum of the
        # heights of left or right subtrees plus '1' for the current node
        return max(left_tree_height, right_tree_height) + 1

    calculate_height(root)
    return tree_diameter
