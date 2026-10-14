import pytest

from twopointers.comparingstringsbackslash import compare


@pytest.mark.parametrize(
    ("str1", "str2", "want"),
    [
        pytest.param("xy#z", "xzz#", True, id="Example 1"),
        pytest.param("xy#z", "xyz#", False, id="Example 2"),
        pytest.param("xp#", "xyz##", True, id="Example 3"),
        pytest.param("xywrrmp", "xywrrmu#p", True, id="Example 4"),
    ],
)
def test_compare(str1: str, str2: str, want: bool) -> None:
    assert compare(str1, str2) == want
