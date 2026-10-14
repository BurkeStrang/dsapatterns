import pytest

from modifiedbinarysearch.bitonicarraymax import find_max_in_bitonic_array


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([1, 3, 8, 12, 4, 2], 12, id="Example 1"),
        pytest.param([3, 8, 3, 1], 8, id="Example 2"),
        pytest.param([1, 3, 8, 12], 12, id="Example 3"),
        pytest.param([10, 9, 8], 10, id="Example 4"),
    ],
)
def test_find_max_in_bitonic_array(arr: list[int], want: int) -> None:
    assert find_max_in_bitonic_array(arr) == want
