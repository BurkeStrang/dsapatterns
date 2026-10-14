import pytest

from common.tree import tree
from treedfs.maxsum import find_maximum_path_sum


@pytest.mark.parametrize(
    ("root", "want"),
    [
        # 2 + 1 + 3
        pytest.param([1, 2, 3], 6, id="simple tree"),
        # 15 + 20 + 7
        pytest.param(
            [-10, 9, 20, None, None, 15, 7], 42, id="tree with negative values"
        ),
    ],
)
def test_find_maximum_path_sum(root: list[int | None], want: int) -> None:
    assert find_maximum_path_sum(tree(root)) == want
