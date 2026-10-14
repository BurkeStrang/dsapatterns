"""Helpers shared by the trie problems."""

from dataclasses import dataclass, field


@dataclass
class TrieNode:
    """One node of a trie of words. Each problem of this pattern builds the
    trie it needs out of these nodes."""

    # The node for each letter that can come next.
    children: dict[str, "TrieNode"] = field(default_factory=dict)
    # Flag to represent if the node is the end of a word.
    is_end: bool = False
