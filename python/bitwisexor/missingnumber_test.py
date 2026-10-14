import pytest

from bitwisexor.missingnumber import find_missing_number


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([1, 2, 3, 5], 4, id="Example 1"),
        pytest.param([1, 2, 4, 5], 3, id="Example 2"),
        pytest.param(list(range(1, 21)), 21, id="Example 3"),
    ],
)
def test_find_missing_number(arr: list[int], want: int) -> None:
    assert find_missing_number(arr) == want
