import pytest

from stack.simplifypath import simplify_path


@pytest.mark.parametrize(
    ("path", "want"),
    [
        pytest.param("/a//b////c/d//././/..", "/a/b/c", id="Example 1"),
        pytest.param("/../", "/", id="Example 2"),
        pytest.param("/home//foo/", "/home/foo", id="Example 3"),
        pytest.param("/", "/", id="Root only"),
        pytest.param("/../../..", "/", id="Multiple .. at root"),
        pytest.param("/./././.", "/", id="Dot only"),
        pytest.param("/a/b/c/", "/a/b/c", id="Trailing slash"),
        pytest.param("/a/./b/../../c/", "/c", id="Complex"),
    ],
)
def test_simplify_path(path: str, want: str) -> None:
    assert simplify_path(path) == want
