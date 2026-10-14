import pytest

from slidingwindow.smallestwindowsubstring import find_substring


@pytest.mark.parametrize(
    ("s", "pattern", "want"),
    [
        pytest.param("aabdec", "abc", "abdec", id="Example 1"),
        pytest.param("aabdec", "abac", "aabdec", id="Example 2"),
        pytest.param("abdbca", "abc", "bca", id="Example 3"),
        pytest.param("adcad", "abc", "", id="Example 4"),
    ],
)
def test_find_substring(s: str, pattern: str, want: str) -> None:
    assert find_substring(s, pattern) == want
