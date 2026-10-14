import pytest

from slidingwindow.subslessthantarget import find_subarrays


@pytest.mark.parametrize(
    ("arr", "target", "want"),
    [
        pytest.param(
            [2, 5, 3, 10],
            30,
            [[2], [2, 5], [5], [5, 3], [3], [10]],
            id="Example 1",
        ),
        pytest.param(
            [8, 2, 6, 5],
            50,
            [[8], [8, 2], [2], [2, 6], [6], [6, 5], [5]],
            id="Example 2",
        ),
        pytest.param([10, 5, 2, 6], 0, [], id="Target 0"),
        pytest.param([1], 2, [[1]], id="Single element < target"),
        pytest.param([5], 5, [], id="Single element >= target"),
    ],
)
def test_find_subarrays(
    arr: list[int], target: int, want: list[list[int]]
) -> None:
    # the subarrays may come back in any order
    assert sorted(find_subarrays(arr, target)) == sorted(want)
