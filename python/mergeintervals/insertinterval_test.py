import pytest

from mergeintervals.insertinterval import insert
from mergeintervals.shared import Interval


@pytest.mark.parametrize(
    ("intervals", "new_interval", "want"),
    [
        pytest.param(
            [Interval(1, 3), Interval(5, 7), Interval(8, 12)],
            Interval(4, 6),
            [Interval(1, 3), Interval(4, 7), Interval(8, 12)],
            id="Example 1",
        ),
        pytest.param(
            [Interval(1, 3), Interval(5, 7), Interval(8, 12)],
            Interval(4, 10),
            [Interval(1, 3), Interval(4, 12)],
            id="Example 2",
        ),
        pytest.param(
            [Interval(2, 3), Interval(5, 7)],
            Interval(1, 4),
            [Interval(1, 4), Interval(5, 7)],
            id="Example 3",
        ),
    ],
)
def test_insert(
    intervals: list[Interval], new_interval: Interval, want: list[Interval]
) -> None:
    assert insert(intervals, new_interval) == want
