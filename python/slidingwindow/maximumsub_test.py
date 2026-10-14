import pytest

from slidingwindow.maximumsub import find_max_sum_sub_array


@pytest.mark.parametrize(
    ("k", "arr", "want"),
    [
        pytest.param(3, [2, 1, 5, 1, 3, 2], 9, id="basic case"),
        pytest.param(1, [4, 2, 7, 1], 7, id="single element window"),
        pytest.param(4, [1, 2, 3, 4], 10, id="window equals array length"),
        pytest.param(3, [], 0, id="empty array"),
    ],
)
def test_find_max_sum_sub_array(k: int, arr: list[int], want: int) -> None:
    assert find_max_sum_sub_array(k, arr) == want
