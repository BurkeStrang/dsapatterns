import pytest

from monotonicstack.dailytemp import daily_temperatures


@pytest.mark.parametrize(
    ("temperatures", "want"),
    [
        pytest.param(
            [70, 73, 75, 71, 69, 72, 76, 73],
            [1, 1, 4, 2, 1, 1, 0, 0],
            id="Example 1",
        ),
        pytest.param([73, 72, 71, 70], [0, 0, 0, 0], id="Example 2"),
        pytest.param([70, 71, 72, 73], [1, 1, 1, 0], id="Example 3"),
        pytest.param([60, 60, 60], [0, 0, 0], id="All same"),
        pytest.param([80], [0], id="Single element"),
    ],
)
def test_daily_temperatures(temperatures: list[int], want: list[int]) -> None:
    assert daily_temperatures(temperatures) == want
