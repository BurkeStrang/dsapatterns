import pytest

from backtracking.combinationsum import combination_sum


@pytest.mark.parametrize(
    ("candidates", "target", "want"),
    [
        pytest.param([2, 3, 6, 7], 7, [[2, 2, 3], [7]], id="test1"),
        pytest.param(
            [2, 4, 6, 8],
            10,
            [
                [2, 2, 2, 2, 2],
                [2, 2, 2, 4],
                [2, 2, 6],
                [2, 4, 4],
                [2, 8],
                [4, 6],
            ],
            id="test2",
        ),
        pytest.param([2], 1, [], id="test3"),
    ],
)
def test_combination_sum(
    candidates: list[int], target: int, want: list[list[int]]
) -> None:
    assert combination_sum(candidates, target) == want
