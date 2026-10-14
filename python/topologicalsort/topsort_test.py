import pytest

from topologicalsort.shared import is_topological_order
from topologicalsort.topsort import sort


@pytest.mark.parametrize(
    ("vertices", "edges"),
    [
        pytest.param(
            6,
            [(5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)],
            id="Test Case 1",
        ),
        pytest.param(4, [(0, 1), (1, 2), (2, 3)], id="Test Case 2"),
    ],
)
def test_sort(vertices: int, edges: list[tuple[int, int]]) -> None:
    got = sort(vertices, edges)
    assert is_topological_order(got, vertices, edges), (
        f"{got} is not a topological order"
    )


def test_a_graph_with_a_cycle_has_no_order() -> None:
    assert sort(3, [(0, 1), (1, 2), (2, 0)]) == []
