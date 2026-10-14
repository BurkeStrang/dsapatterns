import pytest

from graphs.busroutes import num_buses_to_destination


@pytest.mark.parametrize(
    ("routes", "source", "target", "want"),
    [
        pytest.param([[1, 2, 7], [3, 6, 7]], 1, 6, 2, id="example 1"),
        pytest.param(
            [[7, 12], [4, 5, 15], [6], [15, 19], [9, 12, 13]],
            15,
            12,
            -1,
            id="example 2",
        ),
    ],
)
def test_num_buses_to_destination(
    routes: list[list[int]], source: int, target: int, want: int
) -> None:
    assert num_buses_to_destination(routes, source, target) == want
