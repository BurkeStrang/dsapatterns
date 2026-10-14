import pytest

from twoheaps.maxcapital import find_maximum_capital


@pytest.mark.parametrize(
    ("capital", "profits", "number_of_projects", "initial_capital", "want"),
    [
        pytest.param([0, 1, 2], [1, 2, 3], 2, 1, 6, id="basic example"),
        pytest.param(
            [5, 10, 15],
            [1, 2, 3],
            3,
            0,
            0,
            id="not enough capital for any project",
        ),
        pytest.param(
            [0, 0, 0],
            [1, 2, 3],
            2,
            0,
            5,
            id="all projects affordable from start",
        ),
        pytest.param([0], [5], 1, 0, 5, id="single project"),
        pytest.param(
            [0, 1, 2, 3],
            [1, 1, 1, 1],
            4,
            0,
            4,
            id="chain of unlocking projects",
        ),
    ],
)
def test_find_maximum_capital(
    capital: list[int],
    profits: list[int],
    number_of_projects: int,
    initial_capital: int,
    want: int,
) -> None:
    got = find_maximum_capital(
        capital, profits, number_of_projects, initial_capital
    )
    assert got == want
