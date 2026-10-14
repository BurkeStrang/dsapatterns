import pytest

from modifiedbinarysearch.rotationcount import count_rotations


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([10, 15, 1, 3, 8], 2, id="Example 1"),
        pytest.param([4, 5, 7, 9, 10, -1, 2], 5, id="Example 2"),
        pytest.param([1, 3, 8, 10], 0, id="Example 3"),
    ],
)
def test_count_rotations(arr: list[int], want: int) -> None:
    assert count_rotations(arr) == want
