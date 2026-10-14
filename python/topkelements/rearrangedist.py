"""
Given a string and a number ‘K’,
find if the string can be rearranged such that the same characters are at
least ‘K’ distance apart from each other.

Example 1:
Input: "mmpp", K=2
Output: "mpmp" or "pmpm"
Explanation: All same characters are 2 distance apart.

Example 2:
Input: "Programming", K=3
Output: "rgmPrgmiano" or "gmringmrPoa" or "gmrPagimnor" and a few more
Explanation: All same characters are 3 distance apart.

Example 3:
Input: "aab", K=2
Output: "aba"
Explanation: All same characters are 2 distance apart.

Example 4:
Input: "aappa", K=3
Output: ""
Explanation: We cannot find an arrangement of the string where any two 'a'
are 3 distance apart.
"""

import heapq
from collections import Counter, deque


def reorganize_string(s: str, k: int) -> str:
    if k <= 1:
        return s

    char_frequency_map = Counter(s)

    # a max heap of (frequency, letter): the most frequent letter is on top,
    # and among letters with the same frequency the earlier letter comes
    # first, so the result is always the same. heapq only makes min-heaps, so
    # the frequency is stored negated.
    max_heap = [(-count, char) for char, count in char_frequency_map.items()]
    heapq.heapify(max_heap)

    result: list[str] = []
    queue: deque[tuple[int, str]] = deque()
    while max_heap:
        frequency, letter = heapq.heappop(max_heap)
        # append the current character to the result string and decrement its
        # count (the frequency is negated, so adding 1 takes one away)
        result.append(letter)

        # the character has to wait for 'k' steps before it can be used again
        queue.append((frequency + 1, letter))
        if len(queue) == k:
            entry = queue.popleft()
            if entry[0] < 0:
                heapq.heappush(max_heap, entry)

    # if we were successful in appending all the characters to the result
    # string, return it
    if len(result) == len(s):
        return "".join(result)
    return ""
