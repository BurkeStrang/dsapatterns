import pytest

from islandtraversal.numislands import count_islands


@pytest.mark.parametrize(
    ("matrix", "want"),
    [
        pytest.param(
            [[1, 1, 0, 0], [1, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]],
            3,
            id="three islands",
        ),
        pytest.param([[0, 0, 0], [0, 0, 0]], 0, id="no islands"),
        pytest.param([[1, 1], [1, 1]], 1, id="all land"),
    ],
)
def test_count_islands(matrix: list[list[int]], want: int) -> None:
    assert count_islands(matrix) == want
