import pytest

from cyclicalsort.findminmissingposnum import find_mis


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([-3, 1, 5, 4, 2], 3, id="Example 1"),
        pytest.param([3, -2, 0, 1, 2], 4, id="Example 2"),
        pytest.param([3, 2, 5, 1], 4, id="Example 3"),
        pytest.param([33, 37, 5], 1, id="Example 4"),
    ],
)
def test_find_mis(nums: list[int], want: int) -> None:
    assert find_mis(nums) == want
