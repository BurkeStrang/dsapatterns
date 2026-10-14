import pytest

from graphs.findeventualstate import eventual_safe_nodes


@pytest.mark.parametrize(
    ("graph", "want"),
    [
        pytest.param(
            [[1, 2], [2, 3], [2], [], [5], [6], []],
            [3, 4, 5, 6],
            id="Example 1: [3,4,5,6]",
        ),
        pytest.param(
            [[1, 2], [2, 3], [5], [0], [], [], [4]],
            [2, 4, 5, 6],
            id="Example 2: [2,4,5,6]",
        ),
        pytest.param(
            [[1, 2, 3], [2, 3], [3], [], [0, 1, 2]],
            [0, 1, 2, 3, 4],
            id="Example 3: [0,1,2,3,4]",
        ),
    ],
)
def test_eventual_safe_nodes(graph: list[list[int]], want: list[int]) -> None:
    assert eventual_safe_nodes(graph) == want
