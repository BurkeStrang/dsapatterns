import pytest

from cyclicalsort.corruptpair import find_corrupt


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([3, 1, 2, 5, 2], (2, 4), id="Example 1"),
        pytest.param([3, 1, 2, 3, 6, 4], (3, 5), id="Example 2"),
    ],
)
def test_find_corrupt(nums: list[int], want: tuple[int, int] | None) -> None:
    assert find_corrupt(nums) == want
