import pytest

from unionfind.graphbipartite import is_bipartite


@pytest.mark.parametrize(
    ("graph", "want"),
    [
        pytest.param([[1, 3], [0, 2], [1, 3], [0, 2]], True, id="Example 1"),
        pytest.param([[1], [0], [3], [2]], True, id="Example 2"),
        pytest.param(
            [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]], False, id="Example 3"
        ),
        pytest.param([[], [], []], True, id="No edges"),
    ],
)
def test_is_bipartite(graph: list[list[int]], want: bool) -> None:
    assert is_bipartite(graph) == want
