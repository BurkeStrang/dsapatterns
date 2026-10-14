import pytest

from topkelements.topknumbers import find_k_largest_numbers


@pytest.mark.parametrize(
    ("nums", "k", "want"),
    [
        pytest.param([3, 1, 5, 12, 2, 11], 3, [5, 11, 12], id="Example 1"),
        pytest.param([5, 12, 11, -1, 12], 3, [11, 12, 12], id="Example 2"),
        pytest.param(
            [-3, -1, -5, -12, -2, -11], 3, [-3, -2, -1], id="All negative"
        ),
    ],
)
def test_find_k_largest_numbers(
    nums: list[int], k: int, want: list[int]
) -> None:
    # the numbers may come back in any order
    assert sorted(find_k_largest_numbers(nums, k)) == want
