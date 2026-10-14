import pytest

from orderedset.mergesimiliaritems import merge_similar_items


@pytest.mark.parametrize(
    ("items1", "items2", "want"),
    [
        pytest.param(
            [(1, 2), (4, 3)],
            [(2, 1), (4, 3), (3, 4)],
            [[1, 2], [2, 1], [3, 4], [4, 6]],
            id="Example 1",
        ),
        pytest.param([(5, 5)], [(5, 10)], [[5, 15]], id="Example 2"),
        pytest.param(
            [(1, 1), (2, 2)],
            [(3, 3)],
            [[1, 1], [2, 2], [3, 3]],
            id="Example 3",
        ),
        pytest.param(
            [(9, 1), (2, 2)],
            [(5, 3), (2, 4)],
            [[2, 6], [5, 3], [9, 1]],
            id="Unsorted input",
        ),
    ],
)
def test_merge_similar_items(
    items1: list[tuple[int, int]],
    items2: list[tuple[int, int]],
    want: list[list[int]],
) -> None:
    assert merge_similar_items(items1, items2) == want
