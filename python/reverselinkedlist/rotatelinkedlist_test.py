import pytest

from common.list import build_list, list_values
from reverselinkedlist.rotatelinkedlist import rotate


@pytest.mark.parametrize(
    ("head", "rotations", "want"),
    [
        pytest.param([1, 2, 3, 4, 5], 2, [4, 5, 1, 2, 3], id="rotate by 2"),
        pytest.param([1, 2, 3], 0, [1, 2, 3], id="rotate by 0 (no change)"),
        pytest.param(
            [1, 2, 3], 3, [1, 2, 3], id="rotate by length (no change)"
        ),
        pytest.param([1, 2, 3], 5, [2, 3, 1], id="rotate by more than length"),
        pytest.param([1], 1, [1], id="single node"),
        pytest.param([], 3, [], id="empty list"),
    ],
)
def test_rotate(head: list[int], rotations: int, want: list[int]) -> None:
    assert list_values(rotate(build_list(head), rotations)) == want
