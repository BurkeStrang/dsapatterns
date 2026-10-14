import pytest

from common.tree import tree
from levelordertraversal.maxlevelsumbinarytree import max_level_sum


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param([1, 20, 3, 4, 5, None, 8], 2, id="Example 1"),
        pytest.param(
            [10, 5, -3, 3, 2, None, 11, 3, -2, None, 1], 3, id="Example 2"
        ),
        pytest.param([5, 6, 7, 8, None, None, 9, 10], 3, id="Example 3"),
        pytest.param([42], 1, id="Single node"),
        pytest.param([-1, -2, -3], 1, id="Negative values"),
    ],
)
def test_max_level_sum(root: list[int | None], want: int) -> None:
    assert max_level_sum(tree(root)) == want
