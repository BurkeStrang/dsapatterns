import pytest

from twopointers.quadruplesumtotarget import search_quadruplets


@pytest.mark.parametrize(
    ("arr", "target", "want"),
    [
        pytest.param(
            [4, 1, 2, -1, 1, -3],
            1,
            [[-3, -1, 1, 4], [-3, 1, 1, 2]],
            id="Example 1",
        ),
        pytest.param(
            [2, 0, -1, 1, -2, 2],
            2,
            [[-2, 0, 2, 2], [-1, 0, 1, 2]],
            id="Example 2",
        ),
    ],
)
def test_search_quadruplets(
    arr: list[int], target: int, want: list[list[int]]
) -> None:
    # the quadruplets may come back in any order
    assert sorted(search_quadruplets(arr, target)) == want
