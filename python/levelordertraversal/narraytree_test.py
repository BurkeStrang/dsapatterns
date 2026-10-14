import pytest

from levelordertraversal.narraytree import NAryNode, level_order


@pytest.mark.parametrize(
    ("root", "want"),
    [
        pytest.param(
            NAryNode(
                1,
                [
                    NAryNode(2, [NAryNode(5), NAryNode(6)]),
                    NAryNode(3),
                    NAryNode(4),
                ],
            ),
            [[1], [2, 3, 4], [5, 6]],
            id="Example 1: [1,null,2,3,4,null,5,6]",
        ),
        pytest.param(NAryNode(42), [[42]], id="Single node"),
        pytest.param(None, [], id="Empty tree"),
    ],
)
def test_level_order(root: NAryNode | None, want: list[list[int]]) -> None:
    assert level_order(root) == want
