import pytest

from greedy.maxlengthpairchain import find_longest_chain


@pytest.mark.parametrize(
    ("pairs", "want"),
    [
        pytest.param([(1, 2), (3, 4), (2, 3)], 2, id="Example 1"),
        pytest.param([(5, 6), (1, 2), (8, 9), (2, 3)], 3, id="Example 2"),
        pytest.param(
            [(7, 8), (5, 6), (1, 2), (3, 5), (4, 5), (2, 3)], 3, id="Example 3"
        ),
    ],
)
def test_find_longest_chain(pairs: list[tuple[int, int]], want: int) -> None:
    assert find_longest_chain(pairs) == want
