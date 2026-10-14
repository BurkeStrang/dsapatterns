import pytest

from greedy.removeminmax import min_moves


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([3, 2, 5, 1, 4], 3, id="Example 1"),
        pytest.param([7, 5, 6, 8, 1], 2, id="Example 2"),
        pytest.param([9], 1, id="Single element"),
    ],
)
def test_min_moves(nums: list[int], want: int) -> None:
    assert min_moves(nums) == want
