import pytest

from islandtraversal.numofclosed import count_closed_islands


@pytest.mark.parametrize(
    ("matrix", "want"),
    [
        pytest.param(
            [
                [1, 1, 1, 1, 1],
                [1, 0, 0, 0, 1],
                [1, 0, 1, 0, 1],
                [1, 0, 0, 0, 1],
                [1, 1, 1, 1, 1],
            ],
            1,
            id="one simple closed island",
        ),
        pytest.param(
            [
                [1, 1, 0, 1, 0, 0],
                [1, 0, 1, 0, 0, 0],
                [1, 0, 1, 0, 1, 0],
                [1, 1, 0, 1, 0, 0],
            ],
            2,
            id="two closed islands",
        ),
        pytest.param(
            [[0, 1, 1, 1], [1, 0, 0, 1], [1, 1, 0, 1], [1, 1, 1, 1]],
            0,
            id="islands touching border are NOT closed",
        ),
        pytest.param(
            [[1, 1, 1], [1, 1, 1], [1, 1, 1]],
            0,
            id="all land, touching every border",
        ),
        pytest.param([[0, 0, 0], [0, 0, 0], [0, 0, 0]], 0, id="no land at all"),
        pytest.param(
            [
                [1, 1, 1, 1, 1, 1],
                [1, 0, 0, 0, 0, 1],
                [1, 0, 1, 0, 0, 1],
                [0, 0, 0, 0, 1, 1],
                [1, 1, 1, 1, 1, 1],
            ],
            1,
            id="inner island next to one that reaches the border",
        ),
        # the search goes down from the top-left 1 and hits the bottom edge
        # first; the rest of the island must still be marked visited or it is
        # counted again later as a closed island
        pytest.param(
            [
                [0, 0, 0, 0, 0],
                [0, 1, 0, 1, 0],
                [0, 1, 1, 1, 0],
                [0, 1, 0, 0, 0],
                [0, 1, 0, 0, 0],
            ],
            0,
            id="open island whose search reaches the border early",
        ),
    ],
)
def test_count_closed_islands(matrix: list[list[int]], want: int) -> None:
    assert count_closed_islands(matrix) == want
