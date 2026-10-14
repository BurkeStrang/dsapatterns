import pytest

from common.tree import TreeNode, tree
from treebfs.connectlevelordersiblings import connect


def level_order_next(root: TreeNode | None) -> list[list[int]]:
    """Walks the tree using next pointers and returns the values level by
    level."""
    result: list[list[int]] = []
    level_start = root
    while level_start is not None:
        level: list[int] = []
        next_level: TreeNode | None = None
        node: TreeNode | None = level_start
        while node is not None:
            level.append(node.value)
            if next_level is None:
                next_level = node.left or node.right
            node = node.next
        result.append(level)
        level_start = next_level
    return result


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param(
            [1, 2, 3, 4, 5, 6, 7], [[1], [2, 3], [4, 5, 6, 7]], id="Example 1"
        ),
        pytest.param(
            [12, 7, 1, 9, None, 10, 5],
            [[12], [7, 1], [9, 10, 5]],
            id="Example 2",
        ),
        pytest.param([], [], id="Empty tree"),
    ],
)
def test_connect(root: list[int | None], want: list[list[int]]) -> None:
    node = tree(root)
    connect(node)
    assert level_order_next(node) == want
