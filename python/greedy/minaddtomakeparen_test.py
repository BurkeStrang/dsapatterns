import pytest

from greedy.minaddtomakeparen import min_add_to_make_valid


@pytest.mark.parametrize(
    ("s", "want"),
    [
        pytest.param("(()", 1, id="Example 1"),
        pytest.param("))((", 4, id="Example 2"),
        pytest.param("(()())(", 1, id="Example 3"),
        pytest.param("()()", 0, id="Already valid"),
    ],
)
def test_min_add_to_make_valid(s: str, want: int) -> None:
    assert min_add_to_make_valid(s) == want
