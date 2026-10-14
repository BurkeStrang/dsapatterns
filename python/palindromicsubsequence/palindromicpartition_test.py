import pytest

from palindromicsubsequence.palindromicpartition import find_mpp_cuts


@pytest.mark.parametrize(
    ("st", "want"),
    [
        pytest.param("abdbca", 3, id="Example 1"),
        pytest.param("cddpd", 2, id="Example 2"),
        pytest.param("pqr", 2, id="Example 3"),
        pytest.param("pp", 0, id="Example 4"),
    ],
)
def test_find_mpp_cuts(st: str, want: int) -> None:
    assert find_mpp_cuts(st) == want
