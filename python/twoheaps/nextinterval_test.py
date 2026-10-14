import pytest

from twoheaps.nextinterval import Interval, find_next_interval


@pytest.mark.parametrize(
    ("intervals", "want"),
    [
        pytest.param(
            [Interval(2, 3), Interval(3, 4), Interval(5, 6)],
            [1, 2, -1],
            id="basic non-overlapping",
        ),
        pytest.param(
            [Interval(3, 4), Interval(1, 5), Interval(4, 6)],
            [2, -1, -1],
            id="overlapping intervals",
        ),
        pytest.param([Interval(1, 2)], [-1], id="single interval"),
        pytest.param(
            [Interval(1, 1), Interval(3, 4)],
            [0, -1],
            id="self as next interval",
        ),
        pytest.param(
            [Interval(1, 2), Interval(1, 2), Interval(1, 2)],
            [-1, -1, -1],
            id="no next interval for identical",
        ),
        pytest.param(
            [Interval(1, 2), Interval(2, 3), Interval(3, 4)],
            [1, 2, -1],
            id="start equals end",
        ),
    ],
)
def test_find_next_interval(intervals: list[Interval], want: list[int]) -> None:
    assert find_next_interval(intervals) == want
