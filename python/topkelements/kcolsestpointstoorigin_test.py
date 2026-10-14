import pytest

from topkelements.kcolsestpointstoorigin import Point, find_closest_points


@pytest.mark.parametrize(
    ("points", "k", "want"),
    [
        pytest.param(
            [Point(1, 2), Point(1, 3)], 1, [Point(1, 2)], id="Example 1"
        ),
        pytest.param(
            [Point(1, 3), Point(3, 4), Point(2, -1)],
            2,
            [Point(1, 3), Point(2, -1)],
            id="Example 2",
        ),
        pytest.param(
            [Point(1, 2), Point(3, 4), Point(1, -1)],
            2,
            [Point(1, -1), Point(1, 2)],
            id="Example 3",
        ),
        pytest.param(
            [Point(3, 3), Point(5, -1), Point(-2, 4)],
            2,
            [Point(-2, 4), Point(3, 3)],
            id="Example 4",
        ),
        pytest.param(
            [Point(1, 1), Point(1, 1), Point(1, 1)],
            2,
            [Point(1, 1), Point(1, 1)],
            id="All points are the same",
        ),
    ],
)
def test_find_closest_points(
    points: list[Point], k: int, want: list[Point]
) -> None:
    # the points may come back in any order
    assert sorted(find_closest_points(points, k)) == want
