import pytest

from common.tree import tree
from treedfs.pathwithsequence import find_path


@pytest.mark.parametrize(
    ("root", "sequence", "want"),
    [
        pytest.param(
            [1, 7, 9, None, None, 2, 9],
            [1, 9, 9],
            True,
            id="Example 1: Path exists",
        ),
        pytest.param(
            [1, 0, 1, 1, 6, None, 5],
            [1, 0, 7],
            False,
            id="Example 2: Path does not exist",
        ),
        pytest.param([1, 2], [], False, id="Example 3: Empty sequence"),
        pytest.param([], [1], False, id="Example 4: Empty tree"),
        pytest.param([5], [5], True, id="Example 5: Single node match"),
    ],
)
def test_find_path(
    root: list[int | None], sequence: list[int], want: bool
) -> None:
    assert find_path(tree(root), sequence) == want
