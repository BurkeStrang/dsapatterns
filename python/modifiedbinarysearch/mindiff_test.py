import pytest

from modifiedbinarysearch.mindiff import search_min_diff


@pytest.mark.parametrize(
    ("arr", "key", "want"),
    [
        pytest.param([4, 6, 10], 7, 6, id="Example 1"),
        pytest.param([4, 6, 10], 4, 4, id="Example 2"),
        pytest.param([1, 3, 8, 10, 15], 12, 10, id="Example 3"),
        pytest.param([4, 6, 10], 17, 10, id="Example 4"),
    ],
)
def test_search_min_diff(arr: list[int], key: int, want: int) -> None:
    assert search_min_diff(arr, key) == want
