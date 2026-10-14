import pytest

from hashmaps.ransomnote import can_construct


@pytest.mark.parametrize(
    ("ransom_note", "magazine", "want"),
    [
        pytest.param(
            "hello", "hellworld", True, id="can construct hello from hellworld"
        ),
        pytest.param(
            "notes", "stoned", True, id="can construct notes from stoned"
        ),
        pytest.param(
            "apple", "pale", False, id="cannot construct apple from pale"
        ),
        pytest.param("abc", "abc", True, id="exact match"),
        pytest.param("aabb", "ab", False, id="not enough letters"),
        pytest.param("", "anything", True, id="empty ransom note"),
        pytest.param("a", "", False, id="empty magazine"),
    ],
)
def test_can_construct(ransom_note: str, magazine: str, want: bool) -> None:
    assert can_construct(ransom_note, magazine) == want
