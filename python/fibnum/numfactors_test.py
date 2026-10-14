import pytest

from fibnum.numfactors import factors


@pytest.mark.parametrize(
    ("n", "want"),
    [
        pytest.param(4, 4, id="Example 1"),
        pytest.param(5, 6, id="Example 2"),
    ],
)
def test_factors(n: int, want: int) -> None:
    assert factors(n) == want
