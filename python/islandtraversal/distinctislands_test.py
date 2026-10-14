import pytest

from islandtraversal.distinctislands import find_distinct_islands_dfs


@pytest.mark.parametrize(
    ("matrix", "want"),
    [
        pytest.param(
            [[1, 1, 0, 0, 0], [1, 0, 0, 1, 1], [0, 0, 0, 1, 1]],
            2,
            id="two distinct islands",
        ),
        pytest.param(
            [[1, 0, 1, 0], [1, 0, 1, 0]], 1, id="all islands same shape"
        ),
        pytest.param([[0, 0], [0, 0]], 0, id="no islands"),
        pytest.param([[1, 1], [1, 1]], 1, id="single island"),
    ],
)
def test_find_distinct_islands_dfs(matrix: list[list[int]], want: int) -> None:
    assert find_distinct_islands_dfs(matrix) == want
