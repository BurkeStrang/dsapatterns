import pytest

from backtracking.wordsearch import exist

# each row of the board is written as a string, one letter per cell
ROWS = ["ABCE", "SFCS", "ADEE"]


@pytest.mark.parametrize(
    ("word", "want"),
    [
        pytest.param("ABCCED", True, id="test1"),
        pytest.param("SEE", True, id="test2"),
        pytest.param("XYZ", False, id="test3"),
    ],
)
def test_exist(word: str, want: bool) -> None:
    board = [list(row) for row in ROWS]
    assert exist(board, word) == want
    # the board must be put back the way it was
    assert ["".join(row) for row in board] == ROWS
