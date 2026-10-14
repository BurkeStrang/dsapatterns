import pytest

from modifiedbinarysearch.ceiling import search_ceiling_of_a_number


@pytest.mark.parametrize(
    ("arr", "key", "want"),
    [
        pytest.param([4, 6, 10], 5, 1, id="Example 1"),
        pytest.param([1, 3, 8, 10, 15], 8, 2, id="key exists in array"),
        pytest.param([1, 3, 8, 10, 15], 12, 4, id="key between two elements"),
        pytest.param(
            [1, 3, 8, 10, 15], 0, 0, id="key smaller than all elements"
        ),
        pytest.param(
            [1, 3, 8, 10, 15], 20, -1, id="key larger than all elements"
        ),
        pytest.param([1, 3, 8, 10, 15], 1, 0, id="key is smallest element"),
        pytest.param([1, 3, 8, 10, 15], 15, 4, id="key is largest element"),
        pytest.param(
            [2, 4, 6, 8, 10], 5, 2, id="key just below a middle element"
        ),
        pytest.param([5], 5, 0, id="single element - key matches"),
        pytest.param([5], 3, 0, id="single element - key is smaller"),
        pytest.param([5], 7, -1, id="single element - key is larger"),
    ],
)
def test_search_ceiling_of_a_number(
    arr: list[int], key: int, want: int
) -> None:
    assert search_ceiling_of_a_number(arr, key) == want
