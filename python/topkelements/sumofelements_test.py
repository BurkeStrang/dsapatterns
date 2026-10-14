import pytest

from topkelements.sumofelements import find_sum_of_elements


@pytest.mark.parametrize(
    ("nums", "k1", "k2", "want"),
    [
        pytest.param([1, 3, 12, 5, 15, 11], 3, 6, 23, id="basic test"),
        pytest.param([3, 5, 8, 7], 1, 4, 12, id="second test"),
    ],
)
def test_find_sum_of_elements(
    nums: list[int], k1: int, k2: int, want: int
) -> None:
    assert find_sum_of_elements(nums, k1, k2) == want
