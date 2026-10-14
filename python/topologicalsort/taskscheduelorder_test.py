import pytest

from topologicalsort.shared import is_topological_order
from topologicalsort.taskscheduelorder import find_order


@pytest.mark.parametrize(
    ("tasks", "prerequisites"),
    [
        pytest.param(
            6,
            [(2, 5), (0, 5), (0, 4), (1, 4), (3, 2), (1, 3)],
            id="Test Case 1",
        ),
        pytest.param(3, [(0, 1), (1, 2)], id="Test Case 2"),
    ],
)
def test_find_order(tasks: int, prerequisites: list[tuple[int, int]]) -> None:
    got = find_order(tasks, prerequisites)
    assert is_topological_order(got, tasks, prerequisites), (
        f"{got} is not a valid order"
    )


def test_cyclic_prerequisites_have_no_order() -> None:
    assert find_order(3, [(0, 1), (1, 2), (2, 0)]) == []
