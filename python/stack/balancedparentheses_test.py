import pytest

from stack.balancedparentheses import valid_parentheses


@pytest.mark.parametrize(
    ("s1", "want"),
    [
        pytest.param("{[()]}", True, id="Example 1 - balanced"),
        pytest.param("{[}]", False, id="Example 2 - not balanced"),
        pytest.param("(]", False, id="Example 3 - not balanced"),
        pytest.param("", True, id="Empty string - balanced"),
        pytest.param("()[]{}", True, id="Single type - balanced"),
        pytest.param("(((", False, id="Single type - not balanced"),
    ],
)
def test_valid_parentheses(s1: str, want: bool) -> None:
    assert valid_parentheses(s1) == want
