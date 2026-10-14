import pytest

from topologicalsort.minheighttrees import find_trees


@pytest.mark.parametrize(
    ("nodes", "edges", "want"),
    [
        pytest.param(
            5, [(0, 1), (1, 2), (1, 3), (2, 4)], [1, 2], id="Example 1"
        ),
        pytest.param(4, [(0, 1), (0, 2), (2, 3)], [0, 2], id="Example 2"),
        pytest.param(4, [(0, 1), (1, 2), (1, 3)], [1], id="Example 3"),
        pytest.param(4, [(1, 0), (1, 2), (1, 3)], [1], id="Star"),
        pytest.param(
            6,
            [(0, 3), (1, 3), (2, 3), (4, 3), (5, 4)],
            [3, 4],
            id="Two centres",
        ),
        pytest.param(1, [], [0], id="One node"),
        pytest.param(0, [], [], id="No nodes"),
    ],
)
def test_find_trees(
    nodes: int, edges: list[tuple[int, int]], want: list[int]
) -> None:
    # the roots can come back in any order
    assert sorted(find_trees(nodes, edges)) == want
