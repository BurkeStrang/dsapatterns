import pytest

from islandtraversal.maxareaisland import max_area_of_island


@pytest.mark.parametrize(
    ("matrix", "want"),
    [
        pytest.param(
            [[0, 1, 0, 0], [1, 1, 0, 0], [0, 0, 1, 1], [0, 0, 1, 1]],
            4,
            id="two islands",
        ),
        pytest.param([[0, 0, 0], [0, 0, 0]], 0, id="no island"),
        pytest.param(
            [[1, 0, 0, 1], [0, 1, 1, 0], [0, 0, 0, 1]],
            2,
            id="multiple islands",
        ),
    ],
)
def test_max_area_of_island(matrix: list[list[int]], want: int) -> None:
    assert max_area_of_island(matrix) == want
