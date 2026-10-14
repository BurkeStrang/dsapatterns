import pytest

from modifiedbinarysearch.rotatedarraydups import search_rotated_dups


@pytest.mark.parametrize(
    ("arr", "key", "want"),
    [
        pytest.param([3, 7, 3, 3, 3], 7, 1, id="Example 1"),
        pytest.param([3, 3, 3, 7, 3], 7, 3, id="Example 2"),
        pytest.param([3, 3, 7, 3, 3], 7, 2, id="Example 3"),
    ],
)
def test_search_rotated_dups(arr: list[int], key: int, want: int) -> None:
    assert search_rotated_dups(arr, key) == want
