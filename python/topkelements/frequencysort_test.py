import itertools
import sys
from collections import Counter

import pytest

from topkelements.frequencysort import sort_character_by_frequency


def valid_frequency_sort(text: str, output: str) -> bool:
    """Characters with the same frequency may come out in any order, so check
    the shape of the output instead of comparing it with one fixed answer:
    each character sits in a single run as long as its frequency, and the runs
    never get longer."""
    if len(text) != len(output):
        return False
    freq = Counter(text)
    prev_freq = sys.maxsize
    for c, run in itertools.groupby(output):
        count = len(list(run))
        if freq[c] != count or count > prev_freq:
            return False
        prev_freq = count
    return True


@pytest.mark.parametrize(
    "s",
    [
        pytest.param("Programming", id="Example 1"),
        pytest.param("abcbab", id="Example 2"),
    ],
)
def test_sort_character_by_frequency(s: str) -> None:
    got = sort_character_by_frequency(s)
    assert valid_frequency_sort(s, got), f"got {got!r}"
