import pytest

from trie.prefixtrie import Trie


@pytest.mark.parametrize(
    ("inserted", "word", "want_search", "want_starts_with"),
    [
        pytest.param("grape", "grape", True, True, id="grape"),
        pytest.param("grapefruit", "grapefruit", True, True, id="grapefruit"),
        pytest.param("grape", "grap", False, True, id="a prefix of a word"),
        pytest.param("grape", "gr", False, True, id="a shorter prefix"),
        pytest.param("grape", "grapes", False, False, id="a longer word"),
        pytest.param("grape", "gro", False, False, id="a different word"),
    ],
)
def test_trie(
    inserted: str, word: str, want_search: bool, want_starts_with: bool
) -> None:
    trie = Trie()
    trie.insert(inserted)
    assert trie.search(word) == want_search
    assert trie.starts_with(word) == want_starts_with
