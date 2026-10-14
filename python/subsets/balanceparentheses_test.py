import pytest

from subsets.balanceparentheses import generate_valid_parentheses


@pytest.mark.parametrize(
    ("num", "want"),
    [
        pytest.param(2, ["(())", "()()"], id="example 1"),
        pytest.param(
            3,
            ["((()))", "(()())", "(())()", "()(())", "()()()"],
            id="example 2",
        ),
    ],
)
def test_generate_valid_parentheses(num: int, want: list[str]) -> None:
    assert generate_valid_parentheses(num) == want
