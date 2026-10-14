import pytest

from topkelements.kthlargestnuminstream import KthLargest


@pytest.mark.parametrize(
    ("nums", "k", "num", "want"),
    [
        pytest.param([3, 1, 5, 12, 2, 11], 4, 6, 5, id="Example 1"),
        pytest.param([3, 1, 5, 12, 2, 11], 4, 13, 5, id="Example 2"),
        pytest.param([3, 1, 5, 12, 2, 11], 4, 4, 4, id="Example 3"),
    ],
)
def test_add(nums: list[int], k: int, num: int, want: int) -> None:
    assert KthLargest(nums, k).add(num) == want
