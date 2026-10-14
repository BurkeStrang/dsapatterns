import pytest

from fibnum.housetheif import find_max_steal


@pytest.mark.parametrize(
    ("wealth", "want"),
    [
        pytest.param([2, 5, 1, 3, 6, 2, 4], 15, id="Example 1"),
        pytest.param([2, 10, 14, 8, 1], 18, id="Example 2"),
    ],
)
def test_find_max_steal(wealth: list[int], want: int) -> None:
    assert find_max_steal(wealth) == want
