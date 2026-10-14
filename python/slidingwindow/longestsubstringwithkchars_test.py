import pytest

from slidingwindow.longestsubstringwithkchars import find_length


@pytest.mark.parametrize(
    ("s", "k", "want"),
    [
        pytest.param("araaci", 2, 4, id="Example 1"),
        pytest.param("araaci", 1, 2, id="Example 2"),
        pytest.param("cbbebi", 3, 5, id="Example 3"),
    ],
)
def test_find_length(s: str, k: int, want: int) -> None:
    assert find_length(s, k) == want
