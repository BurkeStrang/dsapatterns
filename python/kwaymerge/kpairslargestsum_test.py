import pytest

from kwaymerge.kpairslargestsum import find_k_largest_pairs


# the pairs come back with the smallest sum first; pairs with the same sum
# come back in the order of their numbers
@pytest.mark.parametrize(
    ("nums1", "nums2", "k", "want"),
    [
        pytest.param(
            [9, 8, 2], [6, 3, 1], 3, [[9, 3], [8, 6], [9, 6]], id="Example 1"
        ),
        pytest.param(
            [5, 2, 1], [2, -1], 3, [[2, 2], [5, -1], [5, 2]], id="Example 2"
        ),
    ],
)
def test_find_k_largest_pairs(
    nums1: list[int], nums2: list[int], k: int, want: list[list[int]]
) -> None:
    assert find_k_largest_pairs(nums1, nums2, k) == want
