import pytest

from islandtraversal.hascycle import has_cycle


@pytest.mark.parametrize(
    ("matrix", "want"),
    [
        pytest.param(
            [["A", "B", "C"], ["D", "E", "F"], ["G", "H", "I"]],
            False,
            id="no cycle",
        ),
        pytest.param(
            [["A", "A", "A"], ["A", "B", "A"], ["A", "A", "A"]],
            True,
            id="simple cycle",
        ),
    ],
)
def test_has_cycle(matrix: list[list[str]], want: bool) -> None:
    assert has_cycle(matrix) == want
