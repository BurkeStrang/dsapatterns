import pytest

from topologicalsort.reconstructsequence import can_construct


@pytest.mark.parametrize(
    ("original_seq", "sequences", "want"),
    [
        pytest.param(
            [1, 2, 3, 4], [[1, 2], [2, 3], [3, 4]], True, id="Example 1"
        ),
        pytest.param(
            [1, 2, 3, 4], [[1, 2], [2, 3], [2, 4]], False, id="Example 2"
        ),
        pytest.param(
            [3, 1, 4, 2, 5], [[3, 1, 5], [1, 4, 2, 5]], True, id="Example 3"
        ),
        pytest.param([1, 2, 3], [[3, 2], [2, 1]], False, id="Different order"),
        pytest.param([1, 2, 3], [[1, 2]], False, id="Missing number"),
        pytest.param(
            [1, 2, 3], [[1, 2], [2, 3], [3, 1]], False, id="Cyclic sequences"
        ),
    ],
)
def test_can_construct(
    original_seq: list[int], sequences: list[list[int]], want: bool
) -> None:
    assert can_construct(original_seq, sequences) == want
