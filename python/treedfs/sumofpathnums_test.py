import pytest

from common.tree import tree
from treedfs.sumofpathnums import find_sum_of_path_numbers


@pytest.mark.parametrize(
    ("root", "want"),
    [
        # Paths: 12, 13 => 12+13=25
        pytest.param([1, 2, 3], 25, id="Example 1"),
        # Paths: 101, 106, 115 => 101+106+115=322
        #                       1
        #                     /   \
        #                    0     1
        #                   / \     \
        #                  1   6     5
        pytest.param([1, 0, 1, 1, 6, None, 5], 322, id="Example 2"),
        pytest.param([5], 5, id="Single node"),
        pytest.param([], 0, id="Empty tree"),
    ],
)
def test_find_sum_of_path_numbers(root: list[int | None], want: int) -> None:
    assert find_sum_of_path_numbers(tree(root)) == want
