import pytest

from common.list import build_list, list_values
from reverselinkedlist.reversealtksublist import reverse_alt


@pytest.mark.parametrize(
    ("head", "k", "want"),
    [
        pytest.param(
            [1, 2, 3, 4, 5, 6],
            2,
            [2, 1, 3, 4, 6, 5],
            id="reverse every alternate 2 nodes",
        ),
        pytest.param(
            [1, 2, 3, 4, 5, 6, 7],
            3,
            [3, 2, 1, 4, 5, 6, 7],
            id="reverse every alternate 3 nodes",
        ),
        pytest.param([1, 2], 5, [2, 1], id="k greater than length"),
        pytest.param([1], 2, [1], id="single node"),
        pytest.param([], 2, [], id="empty list"),
    ],
)
def test_reverse_alt(head: list[int], k: int, want: list[int]) -> None:
    assert list_values(reverse_alt(build_list(head), k)) == want
