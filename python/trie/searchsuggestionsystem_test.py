import pytest

from trie.searchsuggestionsystem import suggested_products


@pytest.mark.parametrize(
    ("products", "search_word", "want"),
    [
        pytest.param(
            ["mobile", "mouse", "moneypot", "monitor", "mousepad"],
            "mouse",
            [
                ["mobile", "moneypot", "monitor"],
                ["mobile", "moneypot", "monitor"],
                ["mouse", "mousepad"],
                ["mouse", "mousepad"],
                ["mouse", "mousepad"],
            ],
            id="Test Case 1",
        ),
        pytest.param(["havana"], "havana", [["havana"]] * 6, id="Test Case 2"),
    ],
)
def test_suggested_products(
    products: list[str], search_word: str, want: list[list[str]]
) -> None:
    assert suggested_products(products, search_word) == want
