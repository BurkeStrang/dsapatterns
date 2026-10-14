import pytest

from fastandslowpointers.happynum import is_happy


@pytest.mark.parametrize(
    ("num", "want"),
    [
        pytest.param(19, True, id="Happy number 19"),
        pytest.param(1, True, id="Happy number 1"),
        pytest.param(2, False, id="Unhappy number 2"),
        pytest.param(4, False, id="Unhappy number 4"),
    ],
)
def test_is_happy(num: int, want: bool) -> None:
    assert is_happy(num) == want
