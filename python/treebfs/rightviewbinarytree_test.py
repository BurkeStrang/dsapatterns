import pytest

from common.tree import tree
from treebfs.rightviewbinarytree import right_view


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param([1, 2, 3, 4, 5, 6, 7], [1, 3, 7], id="Example 1"),
        pytest.param(
            [12, 7, 1, None, 9, 10, 5, None, 3], [12, 1, 5, 3], id="Example 2"
        ),
        pytest.param(
            [8, 4, 9, 3, None, None, 10, 2], [8, 9, 10, 2], id="Example 3"
        ),
        pytest.param([], [], id="Empty tree"),
    ],
)
def test_right_view(root: list[int | None], want: list[int]) -> None:
    assert right_view(tree(root)) == want
