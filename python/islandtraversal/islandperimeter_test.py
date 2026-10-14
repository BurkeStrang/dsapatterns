import pytest

from islandtraversal.islandperimeter import find_island_perimeter


@pytest.mark.parametrize(
    ("matrix", "want"),
    [
        # shape is a plus sign → perimeter = 12
        pytest.param(
            [[0, 1, 0], [1, 1, 1], [0, 1, 0]], 12, id="plus sign island"
        ),
        pytest.param([[1]], 4, id="single land cell"),
        # ends (3 sides + 3 sides) + middle (2 + 2)
        pytest.param([[1, 1, 1, 1]], 10, id="single row island"),
        # 2x2 block perimeter = 8
        pytest.param([[1, 1], [1, 1]], 8, id="one big solid block"),
        # Shape:
        # 1 .
        # 1 1
        pytest.param([[1, 0], [1, 1]], 8, id="L-shaped island"),
        pytest.param(
            [[1, 1, 0], [1, 0, 0], [1, 1, 1]], 14, id="island touching border"
        ),
        # A hollow square → perimeter counts both outer and inner edges
        # outer = 12, inner hole = 4 → total = 16
        pytest.param(
            [[1, 1, 1], [1, 0, 1], [1, 1, 1]],
            16,
            id="island with a hole inside",
        ),
    ],
)
def test_find_island_perimeter(matrix: list[list[int]], want: int) -> None:
    assert find_island_perimeter(matrix) == want
