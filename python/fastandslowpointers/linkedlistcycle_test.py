import pytest

from common.list import build_nodes
from fastandslowpointers.linkedlistcycle import has_cycle


@pytest.mark.parametrize(
    ("values", "cycle_start", "want"),
    [
        pytest.param([1, 2, 3], None, False, id="no cycle"),
        pytest.param([1, 2, 3], 0, True, id="cycle exists"),
    ],
)
def test_has_cycle(
    values: list[int], cycle_start: int | None, want: bool
) -> None:
    nodes = build_nodes(values)
    # cycle_start is the index the last node points back to
    if cycle_start is not None:
        nodes[-1].next = nodes[cycle_start]
    assert has_cycle(nodes[0]) == want
