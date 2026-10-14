import pytest

from common.tree import tree
from levelordertraversal.maxwidthbinarytree import width_of_binary_tree


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param([1, 2, 3, 4, None, None, 5], 4, id="Example 1"),
        pytest.param([1, 2, 3, 4, None, 5, 6, None, 7], 4, id="Example 2"),
        pytest.param([1, 2, None, 3, 4, 5], 2, id="Example 3"),
        pytest.param([42], 1, id="Single node"),
        pytest.param([], 0, id="Empty tree"),
    ],
)
def test_width_of_binary_tree(root: list[int | None], want: int) -> None:
    assert width_of_binary_tree(tree(root)) == want
