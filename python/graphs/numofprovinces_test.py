import pytest

from graphs.numofprovinces import find_provinces


@pytest.mark.parametrize(
    ("is_connected", "want"),
    [
        pytest.param(
            [[1, 1, 0], [1, 1, 0], [0, 0, 1]], 2, id="Example 1: Two provinces"
        ),
        pytest.param(
            [[1, 0, 0], [0, 1, 0], [0, 0, 1]],
            3,
            id="Example 2: Three provinces",
        ),
        pytest.param(
            [[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 0], [1, 0, 0, 1]],
            2,
            id="Example 3: Two provinces",
        ),
    ],
)
def test_find_provinces(is_connected: list[list[int]], want: int) -> None:
    assert find_provinces(is_connected) == want
