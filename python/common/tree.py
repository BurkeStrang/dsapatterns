"""Binary trees, as used by the tree patterns."""

from collections import deque


class TreeNode:
    def __init__(
        self,
        value: int,
        left: "TreeNode | None" = None,
        right: "TreeNode | None" = None,
    ) -> None:
        self.value = value
        self.left = left
        self.right = right
        # the node to the right on the same level; only the problems that
        # connect siblings set it
        self.next: TreeNode | None = None

    def __repr__(self) -> str:
        return f"TreeNode({self.value})"


def tree(values: list[int | None]) -> TreeNode | None:
    """Builds a binary tree from its values in level order, with None for a
    missing child, for example tree([1, 2, 3, None, 4]). It keeps the test
    tables short."""
    if not values or values[0] is None:
        return None

    root = TreeNode(values[0])
    queue = deque([root])
    i = 1
    while queue and i < len(values):
        parent = queue.popleft()
        left = values[i]
        if left is not None:
            parent.left = TreeNode(left)
            queue.append(parent.left)
        i += 1
        if i < len(values):
            right = values[i]
            if right is not None:
                parent.right = TreeNode(right)
                queue.append(parent.right)
        i += 1
    return root
