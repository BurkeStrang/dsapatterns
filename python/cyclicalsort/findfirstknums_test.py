import pytest

from cyclicalsort.findfirstknums import find_first_k


@pytest.mark.parametrize(
    ("nums", "k", "want"),
    [
        pytest.param([3, -1, 4, 5, 5], 3, [1, 2, 6], id="Example 1"),
        pytest.param([2, 3, 4], 3, [1, 5, 6], id="Example 2"),
        pytest.param([-2, -3, 4], 2, [1, 2], id="Example 3"),
    ],
)
def test_find_first_k(nums: list[int], k: int, want: list[int]) -> None:
    assert find_first_k(nums, k) == want
