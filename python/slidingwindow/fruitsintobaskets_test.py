import pytest

from slidingwindow.fruitsintobaskets import max_fruit


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param(["A", "B", "C", "A", "C"], 3, id="basic example"),
        pytest.param(["A", "A", "A", "A"], 4, id="all same fruit"),
        pytest.param(
            ["A", "B", "A", "B", "A", "B"], 6, id="two types alternating"
        ),
        pytest.param(["A", "B", "C", "B", "B", "C", "A"], 5, id="three types"),
    ],
)
def test_max_fruit(arr: list[str], want: int) -> None:
    assert max_fruit(arr) == want
