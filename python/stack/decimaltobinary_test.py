import pytest

from stack.decimaltobinary import decimal_to_binary


@pytest.mark.parametrize(
    ("num", "want"),
    [
        pytest.param(2, "10", id="Example 1"),
        pytest.param(7, "111", id="Example 2"),
        pytest.param(18, "10010", id="Example 3"),
    ],
)
def test_decimal_to_binary(num: int, want: str) -> None:
    assert decimal_to_binary(num) == want
