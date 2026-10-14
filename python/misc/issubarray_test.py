import pytest

from misc.issubarray import is_subarray


@pytest.mark.parametrize(
    ("nums", "sub", "want"),
    [
        pytest.param([1, 2, 3], [2, 3], True, id="Example 1"),
        pytest.param(
            [1, 2, 3], [1, 3], False, id="Same numbers, not next to each other"
        ),
        pytest.param([1, 2], [1, 2, 3], False, id="Longer than the array"),
        pytest.param([1, 2], [], True, id="Empty subarray"),
    ],
)
def test_is_subarray(nums: list[int], sub: list[int], want: bool) -> None:
    assert is_subarray(nums, sub) == want
