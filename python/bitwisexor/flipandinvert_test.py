import pytest

from bitwisexor.flipandinvert import flip_and_invert_image


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param(
            [[1, 0, 1], [1, 1, 1], [0, 1, 1]],
            [[0, 1, 0], [0, 0, 0], [0, 0, 1]],
            id="Example 1",
        ),
        pytest.param(
            [[1, 1, 0, 0], [1, 0, 0, 1], [0, 1, 1, 1], [1, 0, 1, 0]],
            [[1, 1, 0, 0], [0, 1, 1, 0], [0, 0, 0, 1], [1, 0, 1, 0]],
            id="Example 2",
        ),
        pytest.param([[1, 0, 0, 1]], [[0, 1, 1, 0]], id="Single row"),
    ],
)
def test_flip_and_invert_image(
    arr: list[list[int]], want: list[list[int]]
) -> None:
    flip_and_invert_image(arr)
    assert arr == want
