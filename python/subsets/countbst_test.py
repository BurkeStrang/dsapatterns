import pytest

from subsets.countbst import count_trees


@pytest.mark.parametrize(
    ("n", "want"),
    [
        pytest.param(2, 2, id="Example 1"),
        pytest.param(3, 5, id="Example 2"),
    ],
)
def test_count_trees(n: int, want: int) -> None:
    assert count_trees(n) == want
