import pytest

from slidingwindow.avg import find_averages


@pytest.mark.parametrize(
    ("k", "arr", "want"),
    [
        pytest.param(
            5,
            [1, 3, 2, 6, -1, 4, 1, 8, 2],
            [2.2, 2.8, 2.4, 3.6, 2.8],
            id="basic case",
        ),
        pytest.param(1, [5, 10, 15], [5.0, 10.0, 15.0], id="window size 1"),
        pytest.param(
            4, [2, 4, 6, 8], [5.0], id="window size equals array length"
        ),
    ],
)
def test_find_averages(k: int, arr: list[int], want: list[float]) -> None:
    assert find_averages(k, arr) == pytest.approx(want)
