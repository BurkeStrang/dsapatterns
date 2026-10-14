import pytest

from common.list import build_list, list_values
from reverselinkedlist.reversesublist import reverse_sub


@pytest.mark.parametrize(
    ("head", "p", "q", "want"),
    [
        pytest.param(
            [1, 2, 3, 4, 5], 2, 4, [1, 4, 3, 2, 5], id="reverse middle sublist"
        ),
        pytest.param([1, 2, 3], 1, 3, [3, 2, 1], id="reverse entire list"),
        pytest.param(
            [1, 2], 2, 2, [1, 2], id="reverse single node (no change)"
        ),
        pytest.param([1, 2], 1, 1, [1, 2], id="reverse head only"),
        pytest.param([1, 2, 3], 1, 2, [2, 1, 3], id="reverse first two"),
        pytest.param([1, 2, 3], 2, 3, [1, 3, 2], id="reverse last two"),
        pytest.param([], 1, 1, [], id="empty list"),
    ],
)
def test_reverse_sub(head: list[int], p: int, q: int, want: list[int]) -> None:
    assert list_values(reverse_sub(build_list(head), p, q)) == want
