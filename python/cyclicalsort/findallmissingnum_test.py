import pytest

from cyclicalsort.findallmissingnum import find_numbers


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([2, 3, 1, 8, 2, 3, 5, 1], [4, 6, 7], id="Example 1"),
        pytest.param([2, 4, 1, 2], [3], id="Example 2"),
        pytest.param([2, 3, 2, 1], [4], id="Example 3"),
    ],
)
def test_find_numbers(nums: list[int], want: list[int]) -> None:
    assert find_numbers(nums) == want
