import pytest

from common.tree import tree
from treedfs.allpathsforsum import find_paths

TWO_PATHS = [5, 4, 8, 11, None, 13, 4, 7, 2, None, None, 5, 1]


@pytest.mark.parametrize(
    ("root", "target", "want"),
    [
        pytest.param([1, 2, 3, 4, 5, 6, 7], 10, [[1, 3, 6]], id="Example 1"),
        pytest.param(
            [12, 7, 1, 9, None, 10, 5], 23, [[12, 1, 10]], id="Example 2"
        ),
        pytest.param(TWO_PATHS, 100, [], id="No path"),
        pytest.param(
            TWO_PATHS, 22, [[5, 4, 11, 2], [5, 8, 4, 5]], id="Two paths"
        ),
        pytest.param([], 0, [], id="Empty tree"),
    ],
)
def test_find_paths(
    root: list[int | None], target: int, want: list[list[int]]
) -> None:
    assert find_paths(tree(root), target) == want
