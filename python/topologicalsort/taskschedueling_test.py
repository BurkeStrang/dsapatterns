import pytest

from topologicalsort.taskschedueling import is_scheduling_possible


@pytest.mark.parametrize(
    ("tasks", "prerequisites", "want"),
    [
        pytest.param(3, [(0, 1), (1, 2)], True, id="Test Case 1"),
        pytest.param(3, [(0, 1), (1, 2), (2, 0)], False, id="Test Case 2"),
        pytest.param(4, [(0, 1), (1, 2), (2, 3)], True, id="Test Case 3"),
    ],
)
def test_is_scheduling_possible(
    tasks: int, prerequisites: list[tuple[int, int]], want: bool
) -> None:
    assert is_scheduling_possible(tasks, prerequisites) == want
