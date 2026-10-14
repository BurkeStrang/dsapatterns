import pytest

from backtracking.factorcombinations import get_factors


@pytest.mark.parametrize(
    ("n", "want"),
    [
        pytest.param(8, [[2, 2, 2], [2, 4]], id="Example 1"),
        pytest.param(20, [[2, 2, 5], [2, 10], [4, 5]], id="Example 2"),
        pytest.param(7, [], id="A prime has none"),
    ],
)
def test_get_factors(n: int, want: list[list[int]]) -> None:
    # the combinations may come back in any order
    assert sorted(get_factors(n)) == want
