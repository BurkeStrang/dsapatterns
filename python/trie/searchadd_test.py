import pytest

from trie.searchadd import Trie


@pytest.mark.parametrize(
    ("add", "word", "want"),
    [
        pytest.param(["cat", "dog"], "c.t", True, id="SearchNode 'c.t'"),
        pytest.param(["cat", "dog"], "d..g", False, id="SearchNode 'd..g'"),
        pytest.param(["hello"], "h.llo", True, id="SearchNode 'h.llo'"),
        pytest.param(["cat", "dog"], "...", True, id="SearchNode '...'"),
        pytest.param(["cat", "dog"], "do", False, id="SearchNode 'do'"),
    ],
)
def test_search_node(add: list[str], word: str, want: bool) -> None:
    trie = Trie()
    for w in add:
        trie.add_word(w)
    assert trie.search_node(word) == want
