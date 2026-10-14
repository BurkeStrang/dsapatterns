import pytest

from twopointers.tripletwithsmallersum import find_triplets


@pytest.mark.parametrize(
    ("arr", "target", "want"),
    [
        pytest.param([-1, 0, 2, 3], 3, 2, id="Example 1"),
        pytest.param([-1, 4, 2, 1, 3], 5, 4, id="Example 2"),
        pytest.param([], 5, 0, id="empty"),
        pytest.param([1, 2], 3, 0, id="two numbers"),
    ],
)
def test_find_triplets(arr: list[int], target: int, want: int) -> None:
    assert find_triplets(arr, target) == want
