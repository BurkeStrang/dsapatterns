import pytest

from topkelements.rearrangestring import rearrange_string


@pytest.mark.parametrize(
    ("s", "want"),
    [
        pytest.param("aappp", "papap", id="Example 1"),
        pytest.param("Programming", "gmrPagimnor", id="Example 2"),
        pytest.param("aapa", "", id="Example 3"),
        pytest.param("a", "a", id="Single character"),
    ],
)
def test_rearrange_string(s: str, want: str) -> None:
    assert rearrange_string(s) == want
