import pytest

from twoheaps.mediannumberstream import Median


@pytest.mark.parametrize(
    "steps",
    [
        # each number to insert, and the median after inserting it
        pytest.param(
            [(1, 1.0), (2, 1.5), (3, 2.0), (4, 2.5), (5, 3.0)], id="in order"
        ),
        pytest.param(
            [(5, 5.0), (3, 4.0), (8, 5.0), (1, 4.0), (2, 3.0)], id="unordered"
        ),
    ],
)
def test_median(steps: list[tuple[int, float]]) -> None:
    m = Median()
    for num, want in steps:
        m.insert_num(num)
        assert m.find_median() == pytest.approx(want), f"after inserting {num}"
