import pytest

from modifiedbinarysearch.numberrange import find_range


@pytest.mark.parametrize(
    ("arr", "key", "want"),
    [
        pytest.param([4, 6, 6, 6, 9], 6, [1, 3], id="example1"),
        pytest.param([1, 3, 8, 10, 15], 10, [3, 3], id="example2"),
        pytest.param([1, 3, 8, 10, 15], 12, [-1, -1], id="example3"),
    ],
)
def test_find_range(arr: list[int], key: int, want: list[int]) -> None:
    assert find_range(arr, key) == want
