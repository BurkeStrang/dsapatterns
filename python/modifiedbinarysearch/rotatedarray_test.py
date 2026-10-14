import pytest

from modifiedbinarysearch.rotatedarray import search_rotated


@pytest.mark.parametrize(
    ("arr", "key", "want"),
    [
        pytest.param([10, 15, 1, 3, 8], 15, 1, id="Example 1"),
        pytest.param([4, 5, 7, 9, 10, -1, 2], 10, 4, id="Example 2"),
        pytest.param([10, 15, 1, 3, 8], 100, -1, id="Example 3"),
        pytest.param([10, 15, 1, 3, 8], 1, 2, id="Example 4"),
    ],
)
def test_search_rotated(arr: list[int], key: int, want: int) -> None:
    assert search_rotated(arr, key) == want
