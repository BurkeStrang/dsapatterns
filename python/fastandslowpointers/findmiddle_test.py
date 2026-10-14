import pytest

from common.list import build_list
from fastandslowpointers.findmiddle import find_middle


@pytest.mark.parametrize(
    ("head", "want"),
    [
        pytest.param([1, 2, 3, 4, 5], 3, id="odd length list"),
        pytest.param([1, 2, 3, 4], 3, id="even length list"),
        pytest.param([1], 1, id="single node"),
        pytest.param([1, 2], 2, id="two nodes"),
        pytest.param([], None, id="empty list"),
    ],
)
def test_find_middle(head: list[int], want: int | None) -> None:
    middle = find_middle(build_list(head))
    # want is the value of the middle node
    assert (middle.value if middle is not None else None) == want
