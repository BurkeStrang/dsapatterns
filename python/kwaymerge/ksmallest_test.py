import pytest

from kwaymerge.ksmallest import find_kth_smallest


@pytest.mark.parametrize(
    ("lists", "k", "want"),
    [
        pytest.param([[2, 6, 8], [3, 6, 7], [1, 3, 4]], 5, 4, id="Example 1"),
        pytest.param([[5, 8, 9], [1, 7]], 3, 7, id="Example 2"),
    ],
)
def test_find_kth_smallest(lists: list[list[int]], k: int, want: int) -> None:
    assert find_kth_smallest(lists, k) == want
