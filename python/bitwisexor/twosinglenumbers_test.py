import pytest

from bitwisexor.twosinglenumbers import find_single_numbers


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([1, 4, 2, 1, 3, 5, 6, 2, 3, 5], [4, 6], id="Example 1"),
        pytest.param([2, 1, 3, 2], [1, 3], id="Example 2"),
    ],
)
def test_find_single_numbers(nums: list[int], want: list[int]) -> None:
    # the two numbers may come back in either order
    assert sorted(find_single_numbers(nums)) == want
