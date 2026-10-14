import pytest

from twopointers.minwindowsort import min_sort


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([1, 2, 5, 3, 7, 10, 9, 12], 5, id="Example 1"),
        pytest.param([1, 3, 2, 0, -1, 7, 10], 5, id="Example 2"),
        pytest.param([1, 2, 3], 0, id="Example 3"),
        pytest.param([3, 2, 1], 3, id="Example 4"),
    ],
)
def test_min_sort(arr: list[int], want: int) -> None:
    assert min_sort(arr) == want
