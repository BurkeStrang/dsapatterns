import pytest

from modifiedbinarysearch.orderagnosticbs import desc_or_asc_search

ASC = [1, 3, 5, 7, 9]
DESC = [9, 7, 5, 3, 1]


@pytest.mark.parametrize(
    ("arr", "key", "want"),
    [
        pytest.param(ASC, 5, 2, id="ascending - key found in middle"),
        pytest.param(ASC, 1, 0, id="ascending - key found at start"),
        pytest.param(ASC, 9, 4, id="ascending - key found at end"),
        pytest.param(ASC, 4, -1, id="ascending - key not found"),
        pytest.param(DESC, 5, 2, id="descending - key found in middle"),
        pytest.param(DESC, 9, 0, id="descending - key found at start"),
        pytest.param(DESC, 1, 4, id="descending - key found at end"),
        pytest.param(DESC, 4, -1, id="descending - key not found"),
        pytest.param([42], 42, 0, id="single element - found"),
        pytest.param([42], 7, -1, id="single element - not found"),
    ],
)
def test_desc_or_asc_search(arr: list[int], key: int, want: int) -> None:
    assert desc_or_asc_search(arr, key) == want
