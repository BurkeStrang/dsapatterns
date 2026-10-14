import pytest

from mergeintervals.intersection import intersecting_intervals
from mergeintervals.shared import Interval


@pytest.mark.parametrize(
    ("arr1", "arr2", "want"),
    [
        pytest.param(
            [Interval(1, 3), Interval(5, 6), Interval(7, 9)],
            [Interval(2, 3), Interval(5, 7)],
            [Interval(2, 3), Interval(5, 6), Interval(7, 7)],
            id="Example 1",
        ),
        pytest.param(
            [Interval(1, 3), Interval(5, 7), Interval(9, 12)],
            [Interval(5, 10)],
            [Interval(5, 7), Interval(9, 10)],
            id="Example 2",
        ),
    ],
)
def test_intersecting_intervals(
    arr1: list[Interval], arr2: list[Interval], want: list[Interval]
) -> None:
    assert intersecting_intervals(arr1, arr2) == want
