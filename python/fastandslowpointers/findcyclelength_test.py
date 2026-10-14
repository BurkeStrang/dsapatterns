import pytest

from common.list import build_nodes
from fastandslowpointers.findcyclelength import find_cycle_length


@pytest.mark.parametrize(
    ("values", "cycle_start", "want"),
    [
        # cycle starts at the second node, length 3
        pytest.param([1, 2, 3, 4], 1, 3, id="cycle of length 3"),
        pytest.param([1, 2, 3], None, 0, id="no cycle"),
        pytest.param([1], 0, 1, id="cycle of length 1 (self loop)"),
    ],
)
def test_find_cycle_length(
    values: list[int], cycle_start: int | None, want: int
) -> None:
    nodes = build_nodes(values)
    # cycle_start is the index the last node points back to
    if cycle_start is not None:
        nodes[-1].next = nodes[cycle_start]
    assert find_cycle_length(nodes[0]) == want
