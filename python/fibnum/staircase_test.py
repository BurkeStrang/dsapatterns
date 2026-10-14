import pytest

from fibnum.staircase import count_ways


@pytest.mark.parametrize(
    ("n", "want"),
    [
        pytest.param(3, 4, id="Example 1"),
        pytest.param(4, 7, id="Example 2"),
    ],
)
def test_count_ways(n: int, want: int) -> None:
    assert count_ways(n) == want
