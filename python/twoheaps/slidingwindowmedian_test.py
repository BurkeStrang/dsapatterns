import pytest

from twoheaps.slidingwindowmedian import find_sliding_window_median


@pytest.mark.parametrize(
    ("nums", "k", "want"),
    [
        pytest.param([1, 2, -1, 3, 5], 2, [1.5, 0.5, 1.0, 4.0], id="k=2"),
        pytest.param([1, 2, -1, 3, 5], 3, [1.0, 2.0, 3.0], id="k=3"),
        pytest.param([4, 1, 3], 1, [4.0, 1.0, 3.0], id="single element window"),
    ],
)
def test_find_sliding_window_median(
    nums: list[int], k: int, want: list[float]
) -> None:
    assert find_sliding_window_median(nums, k) == pytest.approx(want)
