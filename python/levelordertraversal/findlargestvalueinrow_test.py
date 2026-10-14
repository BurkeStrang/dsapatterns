import pytest

from common.tree import tree
from levelordertraversal.findlargestvalueinrow import largest_values


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param([1, 2, 3, 4, 5, None, 6], [1, 3, 6], id="Example 1"),
        pytest.param(
            [7, 4, 8, 2, 5, None, 9, None, 3], [7, 8, 9, 3], id="Example 2"
        ),
        pytest.param([10, 5], [10, 5], id="Example 3"),
        pytest.param([], [], id="Empty tree"),
    ],
)
def test_largest_values(root: list[int | None], want: list[int]) -> None:
    assert largest_values(tree(root)) == want
