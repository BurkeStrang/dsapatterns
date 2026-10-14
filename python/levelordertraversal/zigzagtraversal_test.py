import pytest

from common.tree import tree
from levelordertraversal.zigzagtraversal import traverse_zig_zag


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param(
            [1, 2, 3, 4, 5, None, 6], [[1], [3, 2], [4, 5, 6]], id="Example 1"
        ),
        pytest.param(
            [7, 4, 8, 2, 5, None, 9, None, 3],
            [[7], [8, 4], [2, 5, 9], [3]],
            id="Example 2",
        ),
        pytest.param([42], [[42]], id="Single node"),
        pytest.param([], [], id="Empty tree"),
    ],
)
def test_traverse_zig_zag(
    root: list[int | None], want: list[list[int]]
) -> None:
    assert traverse_zig_zag(tree(root)) == want
