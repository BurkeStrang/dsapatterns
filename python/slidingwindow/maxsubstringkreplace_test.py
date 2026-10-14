import pytest

from slidingwindow.maxsubstringkreplace import max_length_replace


@pytest.mark.parametrize(
    ("s", "k", "want"),
    [
        pytest.param("aabccbb", 2, 5, id="Example 1"),
        pytest.param("abbcb", 1, 4, id="Example 2"),
        pytest.param("abccde", 1, 3, id="Example 3"),
    ],
)
def test_max_length_replace(s: str, k: int, want: int) -> None:
    assert max_length_replace(s, k) == want
