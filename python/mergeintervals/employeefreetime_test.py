import pytest

from mergeintervals.employeefreetime import find_employee_free_time
from mergeintervals.shared import Interval


@pytest.mark.parametrize(
    ("schedule", "want"),
    [
        pytest.param(
            [
                [Interval(1, 3), Interval(5, 6)],
                [Interval(2, 3), Interval(6, 8)],
            ],
            [Interval(3, 5)],
            id="Example 1: two employees, one free interval",
        ),
        pytest.param(
            [
                [Interval(1, 3), Interval(9, 12)],
                [Interval(2, 4)],
                [Interval(6, 8)],
            ],
            [Interval(4, 6), Interval(8, 9)],
            id="Example 2: three employees, two free intervals",
        ),
        pytest.param(
            [
                [Interval(1, 3)],
                [Interval(2, 4)],
                [Interval(3, 5), Interval(7, 9)],
            ],
            [Interval(5, 7)],
            id="Example 3: three employees, one free interval",
        ),
    ],
)
def test_find_employee_free_time(
    schedule: list[list[Interval]], want: list[Interval]
) -> None:
    assert find_employee_free_time(schedule) == want
