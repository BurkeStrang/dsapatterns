import pytest

from stack.nextgreaterelement import next_larger_element


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([4, 5, 2, 25], [5, 25, 25, -1], id="Example 1"),
        pytest.param([13, 7, 6, 12], [-1, 12, 12, -1], id="Example 2"),
        pytest.param([1, 2, 3, 4, 5], [2, 3, 4, 5, -1], id="Example 3"),
    ],
)
def test_next_larger_element(arr: list[int], want: list[int]) -> None:
    assert next_larger_element(arr) == want
