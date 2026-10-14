import pytest

from hashmaps.maxnumballoons import max_number_of_balloons


@pytest.mark.parametrize(
    ("text", "want"),
    [
        pytest.param("balloonballoon", 2, id="Example 1"),
        pytest.param("bbaall", 0, id="Example 2"),
        pytest.param("balloonballoooon", 2, id="Example 3"),
    ],
)
def test_max_number_of_balloons(text: str, want: int) -> None:
    assert max_number_of_balloons(text) == want
