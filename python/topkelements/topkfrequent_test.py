import pytest

from topkelements.topkfrequent import find_top_k_frequent_numbers


# numbers with the same frequency may be picked in any order, so each case
# lists every number that is allowed in the result
@pytest.mark.parametrize(
    ("nums", "k", "valid"),
    [
        pytest.param([1, 3, 5, 12, 11, 12, 11], 2, [11, 12], id="Example 1"),
        pytest.param([5, 12, 11, 3, 11], 2, [11, 5, 12, 3], id="Example 2"),
        pytest.param(
            [1, 1, 1, 3, 3, 3, 5, 5, 5, 12], 2, [1, 3, 5], id="Example 3"
        ),
    ],
)
def test_find_top_k_frequent_numbers(
    nums: list[int], k: int, valid: list[int]
) -> None:
    got = find_top_k_frequent_numbers(nums, k)
    assert len(got) == k
    for v in got:
        assert v in valid, f"unexpected {v} in {got}"
