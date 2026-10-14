import pytest

from palindromicsubsequence.longestpalindromicstring import (
    find_lp_string_length,
)


@pytest.mark.parametrize(
    ("st", "want"),
    [
        pytest.param("abdbca", 3, id="Example 1"),
        pytest.param("cddpd", 3, id="Example 2"),
        pytest.param("pqr", 1, id="Example 3"),
    ],
)
def test_find_lp_string_length(st: str, want: int) -> None:
    assert find_lp_string_length(st) == want
