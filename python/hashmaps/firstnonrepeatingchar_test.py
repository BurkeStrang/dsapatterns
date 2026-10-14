import pytest

from hashmaps.firstnonrepeatingchar import first_uniq_char


@pytest.mark.parametrize(
    ("s", "want"),
    [
        pytest.param("apple", 0, id="Example 1: apple"),
        pytest.param("abcab", 2, id="Example 2: abcab"),
        pytest.param("abab", -1, id="Example 3: abab"),
        pytest.param("z", 0, id="Single character"),
        pytest.param("abcdef", 0, id="All unique"),
        pytest.param("aabbc", 4, id="Last unique"),
    ],
)
def test_first_uniq_char(s: str, want: int) -> None:
    assert first_uniq_char(s) == want
