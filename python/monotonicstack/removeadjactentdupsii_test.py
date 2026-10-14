import pytest

from monotonicstack.removeadjactentdupsii import remove_duplicates_ii


@pytest.mark.parametrize(
    ("s", "k", "want"),
    [
        pytest.param("abbbaaca", 3, "ca", id="remove bbb then aaa"),
        pytest.param("abbaccaa", 3, "abbaccaa", id="no removal possible"),
        pytest.param("abbacccaa", 3, "abb", id="remove ccc then aaa"),
        pytest.param("aaa", 3, "", id="all removed"),
        pytest.param("a", 2, "a", id="single char, k=2"),
        pytest.param("deeedbbcccbdaa", 3, "aa", id="multiple removals"),
    ],
)
def test_remove_duplicates_ii(s: str, k: int, want: str) -> None:
    assert remove_duplicates_ii(s, k) == want
