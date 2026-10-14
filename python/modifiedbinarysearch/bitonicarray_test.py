import pytest

from modifiedbinarysearch.bitonicarray import search_bitonic


@pytest.mark.parametrize(
    ("arr", "key", "want"),
    [
        pytest.param([1, 3, 8, 4, 3], 4, 3, id="Example 1"),
        pytest.param([3, 8, 3, 1], 8, 1, id="Example 2"),
        pytest.param([1, 3, 8, 12], 12, 3, id="Example 3"),
        pytest.param([10, 9, 8], 10, 0, id="Example 4"),
    ],
)
def test_search_bitonic(arr: list[int], key: int, want: int) -> None:
    assert search_bitonic(arr, key) == want
