import pytest

from hashmaps.longestpalindrome import longest_palindrome


@pytest.mark.parametrize(
    ("s", "want"),
    [
        pytest.param("applepie", 5, id="applepie"),
        pytest.param("aabbcc", 6, id="aabbcc"),
        pytest.param("bananas", 5, id="bananas"),
        pytest.param("a", 1, id="single character"),
        pytest.param("abcdef", 1, id="all unique"),
        pytest.param("aabb", 4, id="all pairs"),
    ],
)
def test_longest_palindrome(s: str, want: int) -> None:
    assert longest_palindrome(s) == want
