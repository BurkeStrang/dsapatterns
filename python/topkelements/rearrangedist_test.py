import pytest

from topkelements.rearrangedist import reorganize_string


@pytest.mark.parametrize(
    ("s", "k", "want"),
    [
        pytest.param("mmpp", 2, "mpmp", id="Example 1"),
        pytest.param("Programming", 3, "gmrPagimnor", id="Example 2"),
        pytest.param("aab", 2, "aba", id="Example 3"),
        pytest.param("aappa", 3, "", id="Example 4: not possible"),
        pytest.param("aab", 1, "aab", id="k of 1 changes nothing"),
    ],
)
def test_reorganize_string(s: str, k: int, want: str) -> None:
    assert reorganize_string(s, k) == want
