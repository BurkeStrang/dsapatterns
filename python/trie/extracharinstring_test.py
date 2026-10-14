import pytest

from trie.extracharinstring import min_extra_char


@pytest.mark.parametrize(
    ("s", "dictionary", "want"),
    [
        pytest.param("amazingracecar", ["race"], 10, id="Test Case 1"),
        pytest.param("amazingracecar", ["race", "car"], 7, id="Test Case 2"),
        pytest.param(
            "bookkeeperreading", ["keep", "read"], 9, id="Test Case 3"
        ),
    ],
)
def test_min_extra_char(s: str, dictionary: list[str], want: int) -> None:
    assert min_extra_char(s, dictionary) == want
