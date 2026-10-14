import pytest

from fibnum.fibonaccinumbers import calculate_fibonacci


@pytest.mark.parametrize(
    ("n", "want"),
    [
        pytest.param(0, 0, id="Example 1"),
        pytest.param(1, 1, id="Example 2"),
        pytest.param(2, 1, id="Example 3"),
        pytest.param(3, 2, id="Example 4"),
        pytest.param(4, 3, id="Example 5"),
        pytest.param(55, 139583862445, id="Example 6"),
    ],
)
def test_calculate_fibonacci(n: int, want: int) -> None:
    assert calculate_fibonacci(n) == want
