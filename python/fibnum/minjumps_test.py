import pytest

from fibnum.minjumps import count_min_jumps


@pytest.mark.parametrize(
    ("jumps", "want"),
    [
        pytest.param([2, 1, 1, 1, 4], 3, id="Example 1"),
        pytest.param([1, 1, 3, 6, 9, 3, 0, 1, 3], 4, id="Example 2"),
        pytest.param([1, 0, 2], None, id="Blocked by a zero"),
        pytest.param([0], 0, id="Single element"),
    ],
)
def test_count_min_jumps(jumps: list[int], want: int | None) -> None:
    assert count_min_jumps(jumps) == want
