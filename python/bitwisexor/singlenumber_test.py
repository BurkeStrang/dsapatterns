import pytest

from bitwisexor.singlenumber import find_single_number


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([1, 4, 2, 1, 3, 2, 3], 4, id="Example 1"),
        pytest.param([7, 9, 7], 9, id="Example 2"),
        pytest.param([5, 6, 7, 5, 6], 7, id="Example 3"),
    ],
)
def test_find_single_number(arr: list[int], want: int) -> None:
    assert find_single_number(arr) == want
