import pytest

from unionfind.redundantconnection import find_redundant_connection


@pytest.mark.parametrize(
    ("edges", "want"),
    [
        pytest.param(
            [(1, 2), (1, 3), (3, 4), (1, 4), (1, 5)], [1, 4], id="Example 1"
        ),
        pytest.param([(1, 2), (2, 3), (3, 1), (3, 4)], [3, 1], id="Example 2"),
        pytest.param(
            [(1, 2), (2, 3), (3, 4), (4, 2), (5, 6)], [4, 2], id="Example 3"
        ),
    ],
)
def test_find_redundant_connection(
    edges: list[tuple[int, int]], want: list[int] | None
) -> None:
    assert find_redundant_connection(edges) == want
