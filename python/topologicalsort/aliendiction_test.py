import pytest

from topologicalsort.aliendiction import find_alien_order


@pytest.mark.parametrize(
    ("words", "want"),
    [
        pytest.param(["ba", "bc", "ac", "cab"], "bac", id="Example 1"),
        pytest.param(["cab", "aaa", "aab"], "cab", id="Example 2"),
        pytest.param(
            ["ywx", "wz", "xww", "xz", "zyy", "zwz"], "ywxz", id="Example 3"
        ),
        pytest.param(["abc", "ab"], "", id="Word before its own prefix"),
        pytest.param(["a", "b", "a"], "", id="Cyclic ordering"),
        pytest.param([], "", id="No words"),
    ],
)
def test_find_alien_order(words: list[str], want: str) -> None:
    assert find_alien_order(words) == want
