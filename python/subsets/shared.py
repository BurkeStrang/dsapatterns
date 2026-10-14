"""Helpers shared by the subsets problems."""


def sorted_subsets(subsets: list[list[int]]) -> list[list[int]]:
    """Sorts each subset and then the list of subsets, so that two lists
    holding the same subsets in a different order compare equal."""
    return sorted(sorted(subset) for subset in subsets)
