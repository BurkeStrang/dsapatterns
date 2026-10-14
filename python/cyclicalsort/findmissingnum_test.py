import pytest

from cyclicalsort.findmissingnum import find_missing_number


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([4, 0, 3, 1], 2, id="Example 1"),
        pytest.param([8, 3, 5, 2, 4, 6, 0, 1], 7, id="Example 2"),
    ],
)
def test_find_missing_number(nums: list[int], want: int) -> None:
    assert find_missing_number(nums) == want
