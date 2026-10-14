import pytest

from islandtraversal.floodfill import flood_fill


@pytest.mark.parametrize(
    ("matrix", "x", "y", "new_color", "want"),
    [
        pytest.param(
            [[1, 1, 1], [1, 1, 0], [1, 0, 1]],
            1,
            1,
            2,
            [[2, 2, 2], [2, 2, 0], [2, 0, 1]],
            id="basic flood fill",
        ),
        pytest.param(
            [[0, 0], [0, 1]],
            1,
            1,
            1,
            [[0, 0], [0, 1]],
            id="starting point already new color",
        ),
        pytest.param(
            [[1, 1], [1, 1]],
            3,  # outside grid
            0,
            5,
            [[1, 1], [1, 1]],
            id="no fill when starting outside bounds",
        ),
        pytest.param([[1]], 0, 0, 9, [[9]], id="single cell matrix"),
    ],
)
def test_flood_fill(
    matrix: list[list[int]],
    x: int,
    y: int,
    new_color: int,
    want: list[list[int]],
) -> None:
    flood_fill(matrix, x, y, new_color)
    assert matrix == want
