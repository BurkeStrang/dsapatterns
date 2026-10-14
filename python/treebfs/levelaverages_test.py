import pytest

from common.tree import tree
from treebfs.levelaverages import level_average


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param([1, 2, 3, 4, 5, 6, 7], [1.0, 2.5, 5.5], id="Example 1"),
        pytest.param(
            [12, 7, 1, None, 9, 10, 5], [12.0, 4.0, 8.0], id="Example 2"
        ),
        pytest.param([], [], id="Empty tree"),
    ],
)
def test_level_average(root: list[int | None], want: list[float]) -> None:
    assert level_average(tree(root)) == pytest.approx(want)
