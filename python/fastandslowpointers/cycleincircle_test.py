import pytest

from fastandslowpointers.cycleincircle import loop_exists


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([1, 2, -1, 2, 2], True, id="Example 1"),
        pytest.param([2, 2, -1, 2], True, id="Example 2"),
        pytest.param([2, 1, -1, -2], False, id="Example 3"),
        pytest.param(
            [1, -1, 1, -1], False, id="No cycle, alternating directions"
        ),
        pytest.param([3, 1, 2], True, id="Simple cycle"),
    ],
)
def test_loop_exists(arr: list[int], want: bool) -> None:
    assert loop_exists(arr) == want
