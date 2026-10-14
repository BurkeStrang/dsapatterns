import pytest

from common.list import build_nodes
from fastandslowpointers.startofcycle import find_cycle_start


@pytest.mark.parametrize(
    ("values", "cycle_start"),
    [
        pytest.param([1, 2, 3, 4], 1, id="cycle at node 2"),
        pytest.param([1, 2, 3], 0, id="cycle at the head"),
        pytest.param([1, 2, 3], None, id="no cycle"),
    ],
)
def test_find_cycle_start(values: list[int], cycle_start: int | None) -> None:
    nodes = build_nodes(values)
    # cycle_start is the index the last node points back to
    want = None
    if cycle_start is not None:
        want = nodes[cycle_start]
        nodes[-1].next = want
    # the same node, not just a node with the same value
    assert find_cycle_start(nodes[0]) is want
