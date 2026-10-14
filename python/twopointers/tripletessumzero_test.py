import pytest

from twopointers.tripletessumzero import search_triplets


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param(
            [-3, 0, 1, 2, -1, 1, -2],
            [[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]],
            id="Example 1",
        ),
        pytest.param(
            [-5, 2, -1, -2, 3], [[-5, 2, 3], [-2, -1, 3]], id="Example 2"
        ),
        pytest.param([1, 2, 3], [], id="No triplets"),
    ],
)
def test_search_triplets(arr: list[int], want: list[list[int]]) -> None:
    # the triplets may come back in any order
    assert sorted(search_triplets(arr)) == want
