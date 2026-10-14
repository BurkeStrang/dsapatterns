import pytest

from graphs.findpath import valid_path


@pytest.mark.parametrize(
    ("n", "edges", "start", "end", "want"),
    [
        pytest.param(
            4, [(0, 1), (1, 2), (2, 3)], 0, 3, True, id="path exists simple"
        ),
        pytest.param(
            4,
            [(0, 1), (2, 3)],
            0,
            3,
            False,
            id="no path between disconnected components",
        ),
        pytest.param(
            5, [(0, 1), (3, 4)], 0, 4, False, id="no path with isolated nodes"
        ),
        pytest.param(1, [], 0, 0, True, id="single node graph"),
    ],
)
def test_valid_path(
    n: int, edges: list[tuple[int, int]], start: int, end: int, want: bool
) -> None:
    assert valid_path(n, edges, start, end) == want
