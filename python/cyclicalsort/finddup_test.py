import pytest

from cyclicalsort.finddup import find_dup


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([1, 4, 4, 3, 2], 4, id="Example 1"),
        pytest.param([2, 1, 3, 3, 5, 4], 3, id="Example 2"),
        pytest.param([2, 4, 1, 4, 4], 4, id="Example 3"),
    ],
)
def test_find_dup(nums: list[int], want: int) -> None:
    assert find_dup(nums) == want
