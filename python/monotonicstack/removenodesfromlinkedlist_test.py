import pytest

from common.list import build_list, list_values
from monotonicstack.removenodesfromlinkedlist import remove_nodes


@pytest.mark.parametrize(
    ("head", "want"),
    [
        pytest.param([5, 3, 7, 4, 2, 1], [7, 4, 2, 1], id="Example 1"),
        pytest.param([1, 2, 3, 4, 5], [5], id="Example 2"),
        pytest.param([5, 4, 3, 2, 1], [5, 4, 3, 2, 1], id="Example 3"),
        pytest.param([], [], id="Empty list"),
    ],
)
def test_remove_nodes(head: list[int], want: list[int]) -> None:
    assert list_values(remove_nodes(build_list(head))) == want
