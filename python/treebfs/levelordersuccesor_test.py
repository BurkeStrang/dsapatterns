import pytest

from common.tree import tree
from treebfs.levelordersuccesor import find_successor


@pytest.mark.parametrize(
    ("root", "key", "want"),
    [
        pytest.param([1, 2, 3, 4, 5], 3, 4, id="Example 1"),
        pytest.param([12, 7, 1, 9, None, 10, 5], 9, 10, id="Example 2"),
        pytest.param([12, 7, 1, 9, None, 10, 5], 12, 7, id="Example 3"),
        pytest.param([1, 2], 2, None, id="No successor (last node)"),
        pytest.param([], 1, None, id="Empty tree"),
    ],
)
def test_find_successor(
    root: list[int | None], key: int, want: int | None
) -> None:
    successor = find_successor(tree(root), key)
    # want is the value of the successor
    assert (successor.value if successor is not None else None) == want
