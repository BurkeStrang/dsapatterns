import pytest

from subsets.distinctsubsets import find_subsets
from subsets.shared import sorted_subsets


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([1, 3], [[], [1], [3], [1, 3]], id="example test case 1"),
        pytest.param(
            [1, 2, 3],
            [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]],
            id="example test case 2",
        ),
    ],
)
def test_find_subsets(nums: list[int], want: list[list[int]]) -> None:
    assert sorted_subsets(find_subsets(nums)) == sorted_subsets(want)
