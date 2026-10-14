"""
Given a string,
find if its letters can be rearranged in such a way that no two same
characters come next to each other.

Example 1:
Input: "aappp"
Output: "papap"
Explanation: In "papap", none of the repeating characters come next to each
other.

Example 2:
Input: "Programming"
Output: "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
Explanation: None of the repeating characters come next to each other.

Example 3:
Input: "aapa"
Output: ""
Explanation: In all arrangements of "aapa", atleast two 'a' will come
together e.g., "apaa", "paaa".
"""

import heapq
from collections import Counter


def rearrange_string(s: str) -> str:
    char_frequency_map = Counter(s)

    # a max heap of (frequency, letter): the most frequent letter is on top,
    # and among letters with the same frequency the earlier letter comes
    # first, so the result is always the same. heapq only makes min-heaps, so
    # the frequency is stored negated.
    max_heap = [(-count, char) for char, count in char_frequency_map.items()]
    heapq.heapify(max_heap)

    result: list[str] = []
    # the character used in the previous step, kept out of the heap for one
    # step so that it can't be picked twice in a row
    previous: tuple[int, str] | None = None
    while max_heap:
        count, current_char = heapq.heappop(max_heap)

        # the previous character can be added back to the heap now, if there
        # is any of it left
        if previous is not None and previous[0] < 0:
            heapq.heappush(max_heap, previous)

        # append the current character to the result string and decrement its
        # count (the count is negated, so adding 1 takes one away)
        result.append(current_char)
        previous = (count + 1, current_char)

    # if we were successful in appending all the characters to the result
    # string, return it
    if len(result) == len(s):
        return "".join(result)
    return ""
