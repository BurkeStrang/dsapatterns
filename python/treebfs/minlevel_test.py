import pytest

from common.tree import tree
from treebfs.minlevel import find_depth


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param([1, 2, 3, 4, 5], 2, id="Example 1"),
        pytest.param([1, 2], 2, id="Example 2"),
        pytest.param([1, 2, 3, 4, 5, 6], 3, id="Example 3"),
        pytest.param([1], 1, id="Example 4"),
        pytest.param([], 0, id="Empty tree"),
    ],
)
def test_find_depth(root: list[int | None], want: int) -> None:
    assert find_depth(tree(root)) == want
