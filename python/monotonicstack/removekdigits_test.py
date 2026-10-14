import pytest

from monotonicstack.removekdigits import remove_kdigits


@pytest.mark.parametrize(
    ("num", "k", "want"),
    [
        pytest.param("1432219", 3, "1219", id="Example 1"),
        pytest.param("10200", 1, "200", id="Example 2"),
        pytest.param("1901042", 4, "2", id="Example 3"),
        pytest.param("10", 2, "0", id="Remove all digits"),
        pytest.param("100200", 1, "200", id="Leading zeros after removal"),
        pytest.param("12345", 0, "12345", id="No removal needed"),
    ],
)
def test_remove_kdigits(num: str, k: int, want: str) -> None:
    assert remove_kdigits(num, k) == want
