import pytest

from knapsackdp.knapsack01 import solve_knapsack


@pytest.mark.parametrize(
    ("profits", "weights", "capacity", "want"),
    [
        pytest.param([4, 5, 3, 7], [2, 3, 1, 4], 5, 10, id="Example"),
        pytest.param([1, 6, 10, 16], [1, 2, 3, 5], 7, 22, id="Second example"),
        pytest.param([4, 5], [3, 4], 2, 0, id="Nothing fits"),
    ],
)
def test_solve_knapsack(
    profits: list[int], weights: list[int], capacity: int, want: int
) -> None:
    assert solve_knapsack(profits, weights, capacity) == want
