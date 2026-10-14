import pytest

from palindromicsubsequence.longestpalindromicssubsequence import (
    find_lps_length,
)


@pytest.mark.parametrize(
    ("st", "want"),
    [
        pytest.param("abdbca", 5, id="Example 1"),
        pytest.param("cddpd", 3, id="Example 2"),
        pytest.param("pqr", 1, id="Example 3"),
        pytest.param("", 0, id="Empty string"),
    ],
)
def test_find_lps_length(st: str, want: int) -> None:
    assert find_lps_length(st) == want
