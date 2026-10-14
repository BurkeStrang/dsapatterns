import pytest

from trie.indexparis import index_pairs


@pytest.mark.parametrize(
    ("text", "words", "want"),
    [
        pytest.param(
            "thestarsareout",
            ["star", "stars", "are"],
            [[3, 6], [3, 7], [8, 10]],
            id="Test Case 1",
        ),
        pytest.param(
            "bluebirdskyscraper",
            ["blue", "bird", "sky"],
            [[0, 3], [4, 7], [8, 10]],
            id="Test Case 2",
        ),
    ],
)
def test_index_pairs(
    text: str, words: list[str], want: list[list[int]]
) -> None:
    assert index_pairs(text, words) == want
