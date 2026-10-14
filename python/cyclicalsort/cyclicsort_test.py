import pytest

from cyclicalsort.cyclicsort import sort


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([3, 1, 5, 4, 2], [1, 2, 3, 4, 5], id="Example 1"),
        pytest.param([2, 6, 4, 3, 1, 5], [1, 2, 3, 4, 5, 6], id="Example 2"),
        pytest.param([1, 5, 6, 4, 3, 2], [1, 2, 3, 4, 5, 6], id="Example 3"),
    ],
)
def test_sort(nums: list[int], want: list[int]) -> None:
    sort(nums)
    assert nums == want
