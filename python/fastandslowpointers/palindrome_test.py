import pytest

from common.list import build_list, list_values
from fastandslowpointers.palindrome import is_palindrome


@pytest.mark.parametrize(
    ("values", "want"),
    [
        pytest.param([2, 4, 6, 4, 2], True, id="odd length palindrome"),
        pytest.param([2, 4, 6, 4, 2, 2], False, id="not a palindrome"),
        pytest.param([], True, id="empty list"),
        pytest.param([1], True, id="single node"),
    ],
)
def test_is_palindrome(values: list[int], want: bool) -> None:
    head = build_list(values)
    assert is_palindrome(head) == want
    # the list must be put back the way it was
    assert list_values(head) == values
