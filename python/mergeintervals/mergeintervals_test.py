import pytest

from mergeintervals.mergeintervals import merge
from mergeintervals.shared import Interval


@pytest.mark.parametrize(
    ("intervals", "want"),
    [
        pytest.param(
            [Interval(1, 4), Interval(2, 5), Interval(7, 9)],
            [Interval(1, 5), Interval(7, 9)],
            id="Example 1",
        ),
        pytest.param(
            [Interval(6, 7), Interval(2, 4), Interval(5, 9)],
            [Interval(2, 4), Interval(5, 9)],
            id="Example 2",
        ),
        pytest.param(
            [Interval(1, 4), Interval(2, 6), Interval(3, 5)],
            [Interval(1, 6)],
            id="Example 3",
        ),
        pytest.param(
            [Interval(1, 2), Interval(3, 4), Interval(5, 6)],
            [Interval(1, 2), Interval(3, 4), Interval(5, 6)],
            id="No overlap",
        ),
        pytest.param(
            [Interval(1, 10)], [Interval(1, 10)], id="Single interval"
        ),
    ],
)
def test_merge(intervals: list[Interval], want: list[Interval]) -> None:
    assert merge(intervals) == want
