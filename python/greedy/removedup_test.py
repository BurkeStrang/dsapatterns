import pytest

from greedy.removedup import remove_duplicate_letters


@pytest.mark.parametrize(
    ("s", "want"),
    [
        pytest.param("babac", "abc", id="Example 1"),
        pytest.param("zabccde", "zabcde", id="Example 2"),
        pytest.param("mnopmn", "mnop", id="Example 3"),
    ],
)
def test_remove_duplicate_letters(s: str, want: str) -> None:
    assert remove_duplicate_letters(s) == want
