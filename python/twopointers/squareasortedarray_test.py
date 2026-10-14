import pytest

from twopointers.squareasortedarray import make_squares


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([-2, -1, 0, 2, 3], [0, 1, 4, 4, 9], id="Example 1"),
        pytest.param([-3, -1, 0, 1, 2], [0, 1, 1, 4, 9], id="Example 2"),
        pytest.param([0], [0], id="zero"),
        pytest.param([-1], [1], id="single negative"),
        pytest.param([1, 2, 3], [1, 4, 9], id="all positive"),
        pytest.param([-4, -3, -2, -1], [1, 4, 9, 16], id="all negative"),
    ],
)
def test_make_squares(arr: list[int], want: list[int]) -> None:
    assert make_squares(arr) == want
