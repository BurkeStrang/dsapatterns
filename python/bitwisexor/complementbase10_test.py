import pytest

from bitwisexor.complementbase10 import bitwise_complement


@pytest.mark.parametrize(
    ("num", "want"),
    [
        # number: 5 (binary 101) -> complement: 2 (binary 010)
        pytest.param(5, 2, id="Example 1"),
        # number: 7 (binary 111) -> complement: 0 (binary 000)
        pytest.param(7, 0, id="Example 2"),
        # number: 10 (binary 1010) -> complement: 5 (binary 0101)
        pytest.param(10, 5, id="Example 3"),
    ],
)
def test_bitwise_complement(num: int, want: int) -> None:
    assert bitwise_complement(num) == want
