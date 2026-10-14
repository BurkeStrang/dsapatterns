import pytest

from topkelements.kclosestnumbers import find_closest_elements


@pytest.mark.parametrize(
    ("arr", "k", "x", "want"),
    [
        pytest.param([5, 6, 7, 8, 9], 3, 7, [6, 7, 8], id="Example 1"),
        pytest.param([2, 4, 5, 6, 9], 3, 6, [4, 5, 6], id="Example 2"),
        pytest.param([2, 4, 5, 6, 9], 3, 10, [5, 6, 9], id="Example 3"),
    ],
)
def test_find_closest_elements(
    arr: list[int], k: int, x: int, want: list[int]
) -> None:
    assert find_closest_elements(arr, k, x) == want
