import pytest

from slidingwindow.stringanagrams import find_string_anagrams


@pytest.mark.parametrize(
    ("s", "pattern", "want"),
    [
        pytest.param("ppqp", "pq", [1, 2], id="Example 1"),
        pytest.param("abbcabc", "abc", [2, 3, 4], id="Example 2"),
    ],
)
def test_find_string_anagrams(s: str, pattern: str, want: list[int]) -> None:
    assert find_string_anagrams(s, pattern) == want
