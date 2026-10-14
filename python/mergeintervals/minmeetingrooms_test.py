import pytest

from mergeintervals.minmeetingrooms import Meeting, find_minimum_meeting_rooms


@pytest.mark.parametrize(
    ("meetings", "want"),
    [
        pytest.param(
            [Meeting(1, 4), Meeting(2, 5), Meeting(7, 9)],
            2,
            id="Example 1: overlapping meetings",
        ),
        pytest.param(
            [Meeting(6, 7), Meeting(2, 4), Meeting(8, 12)],
            1,
            id="Example 2: non-overlapping meetings",
        ),
        pytest.param(
            [Meeting(1, 4), Meeting(2, 3), Meeting(3, 6)],
            2,
            id="Example 3: overlapping meetings",
        ),
        pytest.param(
            [Meeting(4, 5), Meeting(2, 3), Meeting(2, 4), Meeting(3, 5)],
            2,
            id="Example 4: complex overlaps",
        ),
    ],
)
def test_find_minimum_meeting_rooms(meetings: list[Meeting], want: int) -> None:
    assert find_minimum_meeting_rooms(meetings) == want
