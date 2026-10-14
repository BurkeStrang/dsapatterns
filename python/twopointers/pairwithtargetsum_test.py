import pytest

from twopointers.pairwithtargetsum import search


@pytest.mark.parametrize(
    ("arr", "target", "want"),
    [
        pytest.param([1, 2, 3, 4, 6], 6, (1, 3), id="Example 1"),
        pytest.param([2, 5, 9, 11], 11, (0, 2), id="Example 2"),
        pytest.param([1, 2, 3, 4, 5], 10, None, id="No pair"),
    ],
)
def test_search(
    arr: list[int], target: int, want: tuple[int, int] | None
) -> None:
    assert search(arr, target) == want
