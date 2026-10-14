import pytest

from monotonicstack.removeadjacentdups import remove_duplicates


@pytest.mark.parametrize(
    ("s", "want"),
    [
        pytest.param("", "", id="empty string"),
        pytest.param("abcd", "abcd", id="no duplicates"),
        pytest.param("abccba", "", id="all removed"),
        pytest.param("aabb", "", id="simple pair"),
        pytest.param("foobar", "fbar", id="single removal"),
        pytest.param("fooobar", "fobar", id="triple duplicate"),
        pytest.param("azxxzy", "ay", id="nested removals"),
        pytest.param("a", "a", id="single char"),
        pytest.param("aaaa", "", id="all same"),
    ],
)
def test_remove_duplicates(s: str, want: str) -> None:
    assert remove_duplicates(s) == want
