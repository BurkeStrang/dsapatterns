import pytest

from unionfind.pathmineffort import minimum_effort_path


@pytest.mark.parametrize(
    ("heights", "want"),
    [
        pytest.param([[1, 2, 3], [3, 8, 4], [5, 3, 5]], 1, id="Example 1"),
        pytest.param([[1, 2, 2], [3, 3, 3], [5, 3, 1]], 2, id="Example 2"),
        pytest.param([[1, 1, 1], [1, 1, 1], [1, 1, 1]], 0, id="Example 3"),
        pytest.param([[7]], 0, id="One cell"),
    ],
)
def test_minimum_effort_path(heights: list[list[int]], want: int) -> None:
    assert minimum_effort_path(heights) == want
