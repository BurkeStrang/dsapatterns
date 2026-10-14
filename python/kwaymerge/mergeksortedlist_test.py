import pytest

from common.list import build_list, list_values
from kwaymerge.mergeksortedlist import merge


@pytest.mark.parametrize(
    ("lists", "want"),
    [
        pytest.param(
            [[2, 6, 8], [3, 6, 7], [1, 3, 4]],
            [1, 2, 3, 3, 4, 6, 6, 7, 8],
            id="Example 1",
        ),
        pytest.param([[5, 8, 9], [1, 7]], [1, 5, 7, 8, 9], id="Example 2"),
        pytest.param([[], [1]], [1], id="An empty list among them"),
    ],
)
def test_merge(lists: list[list[int]], want: list[int]) -> None:
    heads = [build_list(values) for values in lists]
    assert list_values(merge(heads)) == want
