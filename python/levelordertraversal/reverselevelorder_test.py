import pytest

from common.tree import tree
from levelordertraversal.reverselevelorder import traverse


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param(
            [1, 2, 3, 4, 5, 6, 7],
            [[4, 5, 6, 7], [2, 3], [1]],
            id="Example 1",
        ),
        pytest.param(
            [12, 7, 1, None, 9, 10, 5],
            [[9, 10, 5], [7, 1], [12]],
            id="Example 2",
        ),
        pytest.param(
            [6, 5, 2, None, None, 1, 6, 3, 56, None, 3],
            [[3, 56, 3], [1, 6], [5, 2], [6]],
            id="Example 3",
        ),
        pytest.param([], [], id="Empty tree"),
    ],
)
def test_traverse(root: list[int | None], want: list[list[int]]) -> None:
    assert traverse(tree(root)) == want
