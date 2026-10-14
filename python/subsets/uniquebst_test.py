import pytest

from common.tree import TreeNode, tree
from subsets.uniquebst import find_unique_trees


def shape(node: TreeNode | None) -> str:
    """Writes a tree out in preorder, with '-' for a missing child, so that
    two trees with the same shape and values give the same text."""
    if node is None:
        return "-"
    return f"{node.value}({shape(node.left)} {shape(node.right)})"


@pytest.mark.parametrize(
    ("n", "want"),
    [
        # each tree in level order
        pytest.param(2, [[1, None, 2], [2, 1]], id="Example 1"),
        pytest.param(
            3,
            [
                [1, None, 2, None, 3],
                [1, None, 3, 2],
                [2, 1, 3],
                [3, 1, None, None, 2],
                [3, 2, None, 1],
            ],
            id="Example 2",
        ),
        pytest.param(0, [], id="Nothing to build"),
    ],
)
def test_find_unique_trees(n: int, want: list[list[int | None]]) -> None:
    got = [shape(root) for root in find_unique_trees(n)]
    assert got == [shape(tree(root)) for root in want]
