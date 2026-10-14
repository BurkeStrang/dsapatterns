import pytest

from common.tree import tree
from treedfs.treediameter import find_diameter


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param([1], 0, id="Single node"),
        # Path: 4-2-1-3 or 5-2-1-3
        #            1
        #           / \
        #          2   3
        #         / \
        #        4   5
        pytest.param([1, 2, 3, 4, 5], 4, id="Simple tree"),
        # Path: 4-1-2-3
        #       1
        #      / \
        #     4   2
        #          \
        #           3
        pytest.param([1, 4, 2, None, None, None, 3], 4, id="Lopsided tree"),
    ],
)
def test_find_diameter(root: list[int | None], want: int) -> None:
    assert find_diameter(tree(root)) == want
