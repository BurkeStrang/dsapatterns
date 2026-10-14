import pytest

from mergeintervals.conflictingappointments import can_attend_all_appointments
from mergeintervals.shared import Interval


@pytest.mark.parametrize(
    ("intervals", "want"),
    [
        pytest.param(
            [Interval(1, 4), Interval(2, 5), Interval(7, 9)],
            False,
            id="Example 1: overlapping intervals",
        ),
        pytest.param(
            [
                Interval(6, 7),
                Interval(2, 4),
                Interval(13, 14),
                Interval(8, 12),
                Interval(45, 47),
            ],
            True,
            id="Example 2: non-overlapping intervals",
        ),
        pytest.param(
            [Interval(4, 5), Interval(2, 3), Interval(3, 6)],
            False,
            id="Example 3: overlapping intervals",
        ),
    ],
)
def test_can_attend_all_appointments(
    intervals: list[Interval], want: bool
) -> None:
    assert can_attend_all_appointments(intervals) == want
