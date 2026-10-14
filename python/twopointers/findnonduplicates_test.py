import pytest

from twopointers.findnonduplicates import move_elements


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([2, 3, 3, 3, 6, 9, 9], [2, 3, 6, 9], id="Example 1"),
        pytest.param([2, 2, 2, 11], [2, 11], id="Example 2"),
        pytest.param([1, 2, 2], [1, 2], id="duplicate at the end"),
        pytest.param(
            [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
            [0, 1, 2, 3, 4],
            id="many duplicates",
        ),
        pytest.param([1], [1], id="single element"),
        pytest.param([1, 2, 3], [1, 2, 3], id="no duplicates"),
    ],
)
def test_move_elements(arr: list[int], want: list[int]) -> None:
    got = move_elements(arr)
    assert arr[:got] == want
