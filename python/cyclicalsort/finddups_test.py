import pytest

from cyclicalsort.finddups import find_dups


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([3, 4, 4, 5, 5], [5, 4], id="Example 1"),
        pytest.param([5, 4, 7, 2, 3, 5, 3], [3, 5], id="Example 2"),
    ],
)
def test_find_dups(nums: list[int], want: list[int]) -> None:
    assert find_dups(nums) == want
