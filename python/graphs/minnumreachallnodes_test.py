import pytest

from graphs.minnumreachallnodes import find_smallest_set_of_vertices


@pytest.mark.parametrize(
    ("n", "edges", "want"),
    [
        pytest.param(
            6,
            [(0, 1), (0, 2), (2, 5), (3, 4), (4, 2)],
            [0, 3],
            id="Example 1",
        ),
        pytest.param(1, [], [0], id="Single node"),
        pytest.param(3, [], [0, 1, 2], id="Disconnected nodes"),
        pytest.param(
            4,
            [(0, 1), (1, 2), (2, 3)],
            [0],
            id="All nodes connected in a chain",
        ),
    ],
)
def test_find_smallest_set_of_vertices(
    n: int, edges: list[tuple[int, int]], want: list[int]
) -> None:
    assert find_smallest_set_of_vertices(n, edges) == want
