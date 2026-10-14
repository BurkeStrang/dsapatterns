import pytest

from greedy.largestpalindromicnumber import largest_palindromic


@pytest.mark.parametrize(
    ("s", "want"),
    [
        pytest.param("323211444", "432141234", id="Example 1"),
        pytest.param("998877", "987789", id="Example 2"),
        pytest.param("54321", "5", id="Example 3"),
        pytest.param("000", "0", id="Only zeros"),
        pytest.param("10001", "10001", id="Zeros in the middle"),
    ],
)
def test_largest_palindromic(s: str, want: str) -> None:
    assert largest_palindromic(s) == want
