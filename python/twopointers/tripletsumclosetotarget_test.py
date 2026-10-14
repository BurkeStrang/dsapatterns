import pytest

from twopointers.tripletsumclosetotarget import search_triplet


@pytest.mark.parametrize(
    ("arr", "target", "want"),
    [
        pytest.param([-1, 0, 2, 3], 3, 2, id="Example 1"),
        pytest.param([-3, -1, 1, 2], 1, 0, id="Example 2"),
        pytest.param([1, 0, 1, 1], 100, 3, id="Example 3"),
        pytest.param([0, 0, 1, 1, 2, 6], 5, 4, id="Example 4"),
    ],
)
def test_search_triplet(arr: list[int], target: int, want: int) -> None:
    assert search_triplet(arr, target) == want
