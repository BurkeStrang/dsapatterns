import pytest

from palindromicsubsequence.mindeletiontomakepal import find_minimum_deletions


@pytest.mark.parametrize(
    ("st", "want"),
    [
        pytest.param("abdbca", 1, id="Example 1"),
        pytest.param("cddpd", 2, id="Example 2"),
        pytest.param("pqr", 2, id="Example 3"),
        pytest.param("", 0, id="Empty string"),
    ],
)
def test_find_minimum_deletions(st: str, want: int) -> None:
    assert find_minimum_deletions(st) == want
