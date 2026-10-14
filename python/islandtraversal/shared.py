"""Helpers shared by the island traversal problems."""

from collections.abc import Sequence


def in_bounds(matrix: Sequence[Sequence[object]], x: int, y: int) -> bool:
    """Reports whether (x, y) is a cell of the matrix. The traversals step one
    cell past every edge, so x and y may be -1 or one past the end."""
    return 0 <= x < len(matrix) and 0 <= y < len(matrix[0])
