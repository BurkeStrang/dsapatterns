import pytest

from monotonicstack.nextgreaterelement import next_greater_element


@pytest.mark.parametrize(
    ("nums1", "nums2", "want"),
    [
        pytest.param([4, 2, 6], [6, 2, 4, 5, 3, 7], [5, 4, 7], id="Example 1"),
        pytest.param([9, 7, 1], [1, 7, 9, 5, 4, 3], [-1, 9, 7], id="Example 2"),
        pytest.param(
            [5, 12, 3], [12, 3, 5, 4, 10, 15], [10, 15, 5], id="Example 3"
        ),
        pytest.param([8], [8, 7, 6], [-1], id="No greater element"),
        pytest.param([1, 2, 3], [1, 2, 3, 4], [2, 3, 4], id="All increasing"),
    ],
)
def test_next_greater_element(
    nums1: list[int], nums2: list[int], want: list[int]
) -> None:
    assert next_greater_element(nums1, nums2) == want
