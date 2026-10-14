import pytest

from common.tree import tree
from treedfs.countpathssum import count_paths


@pytest.mark.parametrize(
    ("root", "target_sum", "want"),
    [
        # Paths: [1,2], [3]
        pytest.param([1, 2, 3], 3, 2, id="Example 1: Two paths"),
        # Paths: [5,3], [5,2,1], [-3,11]
        pytest.param(
            [10, 5, -3, 3, 2, None, 11, 3, -2, None, 1],
            8,
            3,
            id="Example 2: Multiple paths",
        ),
        pytest.param([1, 2], 100, 0, id="Example 3: No path"),
        pytest.param([], 0, 0, id="Example 4: Empty tree"),
    ],
)
def test_count_paths(
    root: list[int | None], target_sum: int, want: int
) -> None:
    assert count_paths(tree(root), target_sum) == want
