import pytest

from common.list import build_list, list_values
from reverselinkedlist.reverseksublist import reverse_k_sub


@pytest.mark.parametrize(
    ("head", "k", "want"),
    [
        pytest.param(
            [1, 2, 3, 4, 5], 2, [2, 1, 4, 3, 5], id="reverse every 2 nodes"
        ),
        pytest.param(
            [1, 2, 3, 4, 5], 3, [3, 2, 1, 5, 4], id="reverse every 3 nodes"
        ),
        pytest.param([1, 2], 5, [2, 1], id="k greater than length"),
        pytest.param([1], 2, [1], id="single node"),
        pytest.param([], 2, [], id="empty list"),
    ],
)
def test_reverse_k_sub(head: list[int], k: int, want: list[int]) -> None:
    assert list_values(reverse_k_sub(build_list(head), k)) == want
