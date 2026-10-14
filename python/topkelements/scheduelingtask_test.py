import pytest

from topkelements.scheduelingtask import schedule_tasks


@pytest.mark.parametrize(
    ("tasks", "k", "want"),
    [
        pytest.param(["a", "a", "a", "b", "c", "c"], 2, 7, id="Example 1"),
        pytest.param(["a", "b", "a"], 3, 5, id="Example 2"),
    ],
)
def test_schedule_tasks(tasks: list[str], k: int, want: int) -> None:
    assert schedule_tasks(tasks, k) == want
