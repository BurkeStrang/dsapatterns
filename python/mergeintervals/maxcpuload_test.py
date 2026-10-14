import pytest

from mergeintervals.maxcpuload import Job, find_max_cpu_load


@pytest.mark.parametrize(
    ("jobs", "want"),
    [
        pytest.param(
            [Job(1, 4, 3), Job(2, 5, 4), Job(7, 9, 6)],
            7,
            id="Example 1: overlapping jobs",
        ),
        pytest.param(
            [Job(6, 7, 10), Job(2, 4, 11), Job(8, 12, 15)],
            15,
            id="Example 2: non-overlapping jobs",
        ),
        pytest.param(
            [Job(1, 4, 2), Job(2, 4, 1), Job(3, 6, 5)],
            8,
            id="Example 3: all overlap",
        ),
    ],
)
def test_find_max_cpu_load(jobs: list[Job], want: int) -> None:
    assert find_max_cpu_load(jobs) == want
