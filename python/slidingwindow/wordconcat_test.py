import pytest

from slidingwindow.wordconcat import find_word_concatenation


@pytest.mark.parametrize(
    ("s", "words", "want"),
    [
        pytest.param("catfoxcat", ["cat", "fox"], [0, 3], id="Example 1"),
        pytest.param("catcatfoxfox", ["cat", "fox"], [3], id="Example 2"),
        pytest.param("abcdefg", ["hi", "jk"], [], id="No match"),
    ],
)
def test_find_word_concatenation(
    s: str, words: list[str], want: list[int]
) -> None:
    assert find_word_concatenation(s, words) == want
