import pytest

from kwaymerge.ksmallestsortedmatrix import find_kth_smallest_point


@pytest.mark.parametrize(
    ("matrix", "k", "want"),
    [
        pytest.param([[2, 6, 8], [3, 7, 10], [5, 7, 8]], 5, 7, id="Example 1"),
        pytest.param(
            [[1, 20, 30], [2, 21, 31], [3, 22, 32]],
            3,
            3,
            id="Smaller numbers further down",
        ),
    ],
)
def test_find_kth_smallest_point(
    matrix: list[list[int]], k: int, want: int
) -> None:
    assert find_kth_smallest_point(matrix, k) == want
