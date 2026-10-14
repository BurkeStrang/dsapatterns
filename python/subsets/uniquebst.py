"""
Given a number n,
write a function to return all structurally unique Binary Search Trees (BST),
that can store values 1 to n?
"""

from common.tree import TreeNode


def find_unique_trees_recursive(start: int, end: int) -> list[TreeNode | None]:
    """The recursive method to find unique trees."""
    result: list[TreeNode | None] = []
    # base condition, return None for an empty sub-tree
    # consider n=1, in this case we will have start=end=1, this means we
    # should have only one tree we will have two recursive calls,
    # find_unique_trees_recursive(1, 0) & (2, 1) both of these should return
    # None for the left and the right child
    if start > end:
        result.append(None)
        return result

    for i in range(start, end + 1):
        # making 'i' root of the tree
        left_subtrees = find_unique_trees_recursive(start, i - 1)
        right_subtrees = find_unique_trees_recursive(i + 1, end)
        for left_tree in left_subtrees:
            for right_tree in right_subtrees:
                # the trees share their sub-trees, like the Go version
                result.append(TreeNode(i, left_tree, right_tree))
    return result


def find_unique_trees(n: int) -> list[TreeNode | None]:
    if n <= 0:
        return []
    return find_unique_trees_recursive(1, n)
