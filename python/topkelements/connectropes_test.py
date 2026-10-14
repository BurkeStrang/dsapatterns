import pytest

from topkelements.connectropes import minimum_cost_to_connect_ropes


@pytest.mark.parametrize(
    ("rope_lengths", "want"),
    [
        pytest.param([1, 2, 3, 4, 5], 33, id="Example 1"),
        pytest.param([3, 4, 5, 6], 36, id="Example 2"),
        pytest.param([1, 3, 11, 5, 2], 42, id="Example 3"),
    ],
)
def test_minimum_cost_to_connect_ropes(
    rope_lengths: list[int], want: int
) -> None:
    assert minimum_cost_to_connect_ropes(rope_lengths) == want
