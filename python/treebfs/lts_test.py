import pytest

from common.tree import tree
from treebfs.lts import traverse_basic


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param(
            [1, 2, 3, 4, 5, None, 6], [[1], [2, 3], [4, 5, 6]], id="Example 1"
        ),
        pytest.param([42], [[42]], id="Single node"),
        pytest.param([], [], id="Empty tree"),
    ],
)
def test_traverse_basic(root: list[int | None], want: list[list[int]]) -> None:
    assert traverse_basic(tree(root)) == want
