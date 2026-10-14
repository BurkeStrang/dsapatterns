import pytest

from greedy.validpalindrome2 import is_palindrome_possible


@pytest.mark.parametrize(
    ("text", "want"),
    [
        pytest.param("racecar", True, id="Example 1"),
        pytest.param("abeccdeba", True, id="Example 2"),
        pytest.param("abcdef", False, id="Example 3"),
        pytest.param("", True, id="Empty string"),
    ],
)
def test_is_palindrome_possible(text: str, want: bool) -> None:
    assert is_palindrome_possible(text) == want
