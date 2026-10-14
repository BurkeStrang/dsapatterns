import pytest

from common.tree import tree
from treedfs.hassumpath import has_path


@pytest.mark.parametrize(
    ("root", "target", "want"),
    [
        pytest.param([1, 2, 3, 4, 5, 6, 7], 10, True, id="Example 1"),
        pytest.param([12, 7, 1, 9, None, 10, 5], 23, True, id="Example 2"),
        pytest.param([12, 7, 1, 9, None, 10, 5], 16, False, id="Example 3"),
        pytest.param([], 0, False, id="Empty tree"),
    ],
)
def test_has_path(root: list[int | None], target: int, want: bool) -> None:
    assert has_path(tree(root), target) == want
