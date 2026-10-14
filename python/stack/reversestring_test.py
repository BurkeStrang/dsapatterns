import pytest

from stack.reversestring import reverse_string


@pytest.mark.parametrize(
    ("text", "want"),
    [
        pytest.param("Hello, World!", "!dlroW ,olleH", id="Example 1"),
        pytest.param("OpenAI", "IAnepO", id="Example 2"),
        pytest.param("Stacks are fun!", "!nuf era skcatS", id="Example 3"),
    ],
)
def test_reverse_string(text: str, want: str) -> None:
    assert reverse_string(text) == want
