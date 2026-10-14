import pytest

from common.list import build_list, list_values
from reverselinkedlist.reverse import reverse


@pytest.mark.parametrize(
    ("head", "want"),
    [
        pytest.param([1, 2, 3], [3, 2, 1], id="multiple nodes"),
        pytest.param([1], [1], id="single node"),
        pytest.param([], [], id="empty list"),
    ],
)
def test_reverse(head: list[int], want: list[int]) -> None:
    assert list_values(reverse(build_list(head))) == want
