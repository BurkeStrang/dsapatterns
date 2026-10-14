import pytest

from common.tree import tree
from levelordertraversal.evenoddtree import is_even_odd_tree


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param(
            [1, 10, 4, 3, 7], True, id="Example 1: Valid Even-Odd Tree"
        ),
        pytest.param(
            [5, 9, 3, 12, None, None, 8],
            False,
            id="Example 2: Invalid Even-Odd Tree (odd values at level 1)",
        ),
        pytest.param(
            [7, 10, 2, 12, 8],
            False,
            id="Example 3: Invalid Even-Odd Tree (even values at even level)",
        ),
        pytest.param([1], True, id="Single node (odd value at level 0)"),
        pytest.param([2], False, id="Single node (even value at level 0)"),
        pytest.param([], True, id="Empty tree"),
    ],
)
def test_is_even_odd_tree(root: list[int | None], want: bool) -> None:
    assert is_even_odd_tree(tree(root)) == want
