import pytest

from twopointers.dutchnationalflag import dutch


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([1, 0, 2, 1, 0], [0, 0, 1, 1, 2], id="example1"),
        pytest.param([2, 2, 0, 1, 2, 0], [0, 0, 1, 2, 2, 2], id="example2"),
        pytest.param([0, 0, 0], [0, 0, 0], id="all zeros"),
        pytest.param([2, 2, 2], [2, 2, 2], id="all twos"),
        pytest.param(
            [0, 0, 1, 1, 2, 2], [0, 0, 1, 1, 2, 2], id="already sorted"
        ),
        pytest.param([1], [1], id="single element"),
    ],
)
def test_dutch(arr: list[int], want: list[int]) -> None:
    dutch(arr)
    assert arr == want
