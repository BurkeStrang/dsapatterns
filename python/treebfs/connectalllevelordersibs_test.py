import pytest

from common.tree import TreeNode, tree
from treebfs.connectalllevelordersibs import connect_all


def flatten_next(root: TreeNode | None) -> list[int]:
    """Walks the tree using next pointers and returns the values in order."""
    result: list[int] = []
    node = root
    while node is not None:
        result.append(node.value)
        node = node.next
    return result


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param(
            [1, 2, 3, 4, 5, 6, 7], [1, 2, 3, 4, 5, 6, 7], id="Example 1"
        ),
        pytest.param(
            [12, 7, 1, 9, None, 10, 5], [12, 7, 1, 9, 10, 5], id="Example 2"
        ),
        pytest.param([], [], id="Empty tree"),
    ],
)
def test_connect_all(root: list[int | None], want: list[int]) -> None:
    node = tree(root)
    connect_all(node)
    assert flatten_next(node) == want
