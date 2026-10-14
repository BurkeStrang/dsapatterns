import pytest

from stack.sortingstack import sort_stack


# the stacks are written with the bottom element first and the top last
@pytest.mark.parametrize(
    ("stack", "want"),
    [
        pytest.param(
            [34, 3, 31, 98, 92, 23], [3, 23, 31, 34, 92, 98], id="Example 1"
        ),
        pytest.param(
            [4, 3, 2, 10, 12, 1, 5, 6],
            [1, 2, 3, 4, 5, 6, 10, 12],
            id="Example 2",
        ),
        pytest.param([20, 10, -5, -1], [-5, -1, 10, 20], id="Example 3"),
    ],
)
def test_sort_stack(stack: list[int], want: list[int]) -> None:
    assert sort_stack(stack) == want
