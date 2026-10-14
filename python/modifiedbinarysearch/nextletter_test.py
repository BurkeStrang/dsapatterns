import pytest

from modifiedbinarysearch.nextletter import search_next_letter

LETTERS = ["a", "c", "f", "h"]


@pytest.mark.parametrize(
    ("letters", "key", "want"),
    [
        pytest.param(LETTERS, "f", "h", id="key in middle of array"),
        pytest.param(LETTERS, "b", "c", id="key before first element"),
        pytest.param(LETTERS, "a", "c", id="key is smallest element"),
        pytest.param(
            LETTERS, "h", "a", id="key is largest element - wraps around"
        ),
        pytest.param(
            LETTERS, "z", "a", id="key larger than all - wraps around"
        ),
        pytest.param(
            ["c", "f", "j"], "a", "c", id="key smaller than all elements"
        ),
        pytest.param(LETTERS, "g", "h", id="key between two adjacent elements"),
        pytest.param(["m"], "m", "m", id="single element - wraps around"),
    ],
)
def test_search_next_letter(letters: list[str], key: str, want: str) -> None:
    assert search_next_letter(letters, key) == want
