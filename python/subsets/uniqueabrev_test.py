import pytest

from subsets.uniqueabrev import generate_generalized_abbreviation


@pytest.mark.parametrize(
    ("word", "want"),
    [
        pytest.param(
            "word",
            [
                "word",
                "1ord",
                "w1rd",
                "wo1d",
                "wor1",
                "2rd",
                "w2d",
                "wo2",
                "1o1d",
                "1or1",
                "w1r1",
                "1o2",
                "2r1",
                "3d",
                "w3",
                "4",
            ],
            id="word",
        ),
    ],
)
def test_generate_generalized_abbreviation(word: str, want: list[str]) -> None:
    # the abbreviations may come back in any order
    assert sorted(generate_generalized_abbreviation(word)) == sorted(want)
