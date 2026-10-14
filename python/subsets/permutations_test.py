import pytest

from subsets.permutations import find_permutations


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param(
            [1, 2, 3],
            [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]],
            id="3 elements",
        ),
    ],
)
def test_find_permutations(nums: list[int], want: list[list[int]]) -> None:
    # the permutations may come back in any order
    assert sorted(find_permutations(nums)) == want
