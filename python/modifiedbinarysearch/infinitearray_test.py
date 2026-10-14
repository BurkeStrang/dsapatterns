import pytest

from modifiedbinarysearch.infinitearray import (
    ArrayReader,
    search_infinite_sorted_array,
)

EVENS = list(range(4, 31, 2))  # 4, 6, ..., 30


@pytest.mark.parametrize(
    ("arr", "key", "want"),
    [
        pytest.param(EVENS, 16, 6, id="Example 1"),
        pytest.param(EVENS, 11, -1, id="Example 2"),
        pytest.param([1, 3, 8, 10, 15], 15, 4, id="Example 3"),
    ],
)
def test_search_infinite_sorted_array(
    arr: list[int], key: int, want: int
) -> None:
    assert search_infinite_sorted_array(ArrayReader(arr), key) == want
