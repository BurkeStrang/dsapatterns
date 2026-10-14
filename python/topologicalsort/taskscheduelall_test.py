import pytest

from topologicalsort.taskscheduelall import print_orders


# want lists every valid ordering; they can come back in any order
@pytest.mark.parametrize(
    ("tasks", "prerequisites", "want"),
    [
        pytest.param(
            4,
            [(3, 2), (3, 0), (2, 0), (2, 1)],
            [[3, 2, 0, 1], [3, 2, 1, 0]],
            id="Example 1: two orderings",
        ),
        pytest.param(
            3, [(0, 1), (1, 2)], [[0, 1, 2]], id="Example 2: one ordering"
        ),
        pytest.param(
            6,
            [(2, 5), (0, 5), (0, 4), (1, 4), (3, 2), (1, 3)],
            [
                [0, 1, 4, 3, 2, 5],
                [0, 1, 3, 4, 2, 5],
                [0, 1, 3, 2, 4, 5],
                [0, 1, 3, 2, 5, 4],
                [1, 0, 3, 4, 2, 5],
                [1, 0, 3, 2, 4, 5],
                [1, 0, 3, 2, 5, 4],
                [1, 0, 4, 3, 2, 5],
                [1, 3, 0, 2, 4, 5],
                [1, 3, 0, 2, 5, 4],
                [1, 3, 0, 4, 2, 5],
                [1, 3, 2, 0, 5, 4],
                [1, 3, 2, 0, 4, 5],
            ],
            id="Example 3: thirteen orderings",
        ),
        pytest.param(
            3,
            [],
            [[0, 1, 2], [0, 2, 1], [1, 0, 2], [1, 2, 0], [2, 0, 1], [2, 1, 0]],
            id="No prerequisites: every arrangement",
        ),
        pytest.param(
            3,
            [(0, 1), (1, 2), (2, 0)],
            [],
            id="Cyclic prerequisites: no ordering",
        ),
        pytest.param(0, [], [], id="No tasks"),
    ],
)
def test_print_orders(
    tasks: int, prerequisites: list[tuple[int, int]], want: list[list[int]]
) -> None:
    assert sorted(print_orders(tasks, prerequisites)) == sorted(want)
