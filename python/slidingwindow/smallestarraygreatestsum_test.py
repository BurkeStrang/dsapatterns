import pytest

from slidingwindow.smallestarraygreatestsum import find_min_sub_array


@pytest.mark.parametrize(
    ("s", "arr", "want"),
    [
        pytest.param(7, [2, 1, 5, 2, 3, 2], 2, id="Example 1"),
        pytest.param(7, [2, 1, 5, 2, 8], 1, id="Example 2"),
        pytest.param(8, [3, 4, 1, 1, 6], 3, id="Example 3"),
        pytest.param(20, [1, 2, 3, 4], 0, id="No subarray meets S"),
    ],
)
def test_find_min_sub_array(s: int, arr: list[int], want: int) -> None:
    assert find_min_sub_array(s, arr) == want
