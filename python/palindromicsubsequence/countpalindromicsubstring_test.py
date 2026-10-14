import pytest

from palindromicsubsequence.countpalindromicsubstring import find_cps


@pytest.mark.parametrize(
    ("st", "want"),
    [
        pytest.param("abdbca", 7, id="Example 1"),
        pytest.param("cddpd", 7, id="Example 2"),
        pytest.param("pqr", 3, id="Example 3"),
        pytest.param("", 0, id="Empty string"),
    ],
)
def test_find_cps(st: str, want: int) -> None:
    assert find_cps(st) == want
