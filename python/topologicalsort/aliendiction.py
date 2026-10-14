"""
There is a dictionary containing words from an alien language
for which we don't know the ordering of the letters.
Given a list of strings words from the alien language's dictionary.
All strings in words are sorted lexicographically by the rules of this new
language.
Return a string of the unique letters in the new alien language
sorted in lexicographically increasing order by the new language's rules.
It is given that the input is a valid dictionary and there exists an ordering
among its letters.

Example 1:
Input: Words: ["ba", "bc", "ac", "cab"]
Output: bac
Explanation: Given that the words are sorted lexicographically by the rules
of the alien language, so
from the given words we can conclude the following ordering among its
characters:
1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
2. From "bc" and "ac", we can conclude that 'b' comes before 'a'
From the above two points, we can conclude that the correct character order
is: "bac"

Example 2:
Input: Words: ["cab", "aaa", "aab"]
Output: cab
Explanation: From the given words we can conclude the following ordering
among its characters:
1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'
From the above two points, we can conclude that the correct character order
is: "cab"

Example 3:
Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
Output: ywxz
Explanation: From the given words we can conclude the following ordering
among its characters:
1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'

From the above five points, we can conclude that the correct character order
is: "ywxz"
Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of only lowercase English letters.
"""

import itertools
from collections import deque


def find_alien_order(words: list[str]) -> str:
    if not words:
        return ""

    # a. Initialize the graph; dicts keep the letters in the order they first
    # appear, so the sources are always visited in the same order
    in_degree: dict[str, int] = {}
    graph: dict[str, list[str]] = {}
    for word in words:
        for character in word:
            in_degree.setdefault(character, 0)
            graph.setdefault(character, [])

    # b. Build the graph
    for w1, w2 in itertools.pairwise(words):
        # find ordering of characters from adjacent words
        found_difference = False
        for parent, child in zip(w1, w2, strict=False):
            if parent != child:
                graph[parent].append(child)
                in_degree[child] += 1
                found_difference = True
                break

        # a word cannot come before one of its own prefixes: "abc" before
        # "ab" is not a valid dictionary, so no letter ordering can explain
        # it
        if not found_difference and len(w1) > len(w2):
            return ""

    # c. Find all sources i.e., all vertices with 0 in-degrees
    sources = deque(letter for letter, count in in_degree.items() if count == 0)

    # d. For each source, add it to the sorted_order and subtract one from
    # all of its children's in-degrees if a child's in-degree becomes zero,
    # add it to sources queue
    sorted_order: list[str] = []
    while sources:
        vertex = sources.popleft()
        sorted_order.append(vertex)
        for child in graph[vertex]:
            in_degree[child] -= 1
            if in_degree[child] == 0:
                sources.append(child)

    # if sorted_order doesn't contain all characters, there is a cyclic
    # dependency between characters, therefore, we will not be able to find
    # the correct ordering of the characters
    if len(sorted_order) != len(in_degree):
        return ""

    return "".join(sorted_order)
