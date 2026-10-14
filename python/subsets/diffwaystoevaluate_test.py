import pytest

from subsets.diffwaystoevaluate import diff_ways_to_evaluate_expression


@pytest.mark.parametrize(
    ("expression", "want"),
    [
        pytest.param("2+3*2", [8, 10], id="parentheses addition"),
        pytest.param(
            "2*4-3*5", [-22, 10, -7, 10, 25], id="parentheses multiple"
        ),
    ],
)
def test_diff_ways_to_evaluate_expression(
    expression: str, want: list[int]
) -> None:
    assert diff_ways_to_evaluate_expression(expression) == want
