import pytest

from common.list import build_list, list_values
from fastandslowpointers.rearangelist import rearange_list


@pytest.mark.parametrize(
    ("head", "want"),
    [
        pytest.param([1, 2, 3, 4], [1, 4, 2, 3], id="even length list"),
        pytest.param([1, 2, 3], [1, 3, 2], id="odd length list"),
        pytest.param([1], [1], id="single node"),
        pytest.param([], [], id="empty list"),
    ],
)
def test_rearange_list(head: list[int], want: list[int]) -> None:
    assert list_values(rearange_list(build_list(head))) == want
