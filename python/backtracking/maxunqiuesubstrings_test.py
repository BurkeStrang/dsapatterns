import pytest

from backtracking.maxunqiuesubstrings import max_unique_split


@pytest.mark.parametrize(
    ("s", "want"),
    [
        pytest.param("ababccc", 5, id="Example 1"),
        pytest.param("aba", 2, id="Example 2"),
        pytest.param("aa", 1, id="Example 3"),
    ],
)
def test_max_unique_split(s: str, want: int) -> None:
    assert max_unique_split(s) == want
