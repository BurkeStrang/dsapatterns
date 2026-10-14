import pytest

from slidingwindow.maxsubarrayonesreplace import max_ones_length


@pytest.mark.parametrize(
    ("arr", "k", "want"),
    [
        pytest.param([0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], 2, 6, id="Example 1"),
        pytest.param(
            [0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], 3, 9, id="Example 2"
        ),
        pytest.param([1, 0, 0, 1, 1, 0, 1, 1], 2, 6, id="Example 3"),
    ],
)
def test_max_ones_length(arr: list[int], k: int, want: int) -> None:
    assert max_ones_length(arr, k) == want
