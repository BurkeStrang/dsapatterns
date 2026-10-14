import pytest

from slidingwindow.permutationsinstring import find_permutation


@pytest.mark.parametrize(
    ("s", "pattern", "want"),
    [
        pytest.param("oidbcaf", "abc", True, id="Example 1"),
        pytest.param("odicf", "dc", False, id="Example 2"),
        pytest.param("bcdxabcdy", "bcdyabcdx", True, id="Example 3"),
        pytest.param("aaacb", "abc", True, id="Example 4"),
    ],
)
def test_find_permutation(s: str, pattern: str, want: bool) -> None:
    assert find_permutation(s, pattern) == want
