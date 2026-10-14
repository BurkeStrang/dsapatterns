"""Helpers shared by the union find problems."""


class UnionFind:
    """Keeps track of which set every element belongs to. Each set is a tree,
    and the root of the tree stands for the whole set."""

    def __init__(self, size: int) -> None:
        """Makes 'size' sets, each holding one element."""
        self.parent = list(range(size))
        self.rank = [0] * size

    def find(self, x: int) -> int:
        """Returns the root of the set that x belongs to."""
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]

    def unite(self, x: int, y: int) -> None:
        """Merges the sets that x and y belong to."""
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x == root_y:
            return

        # Union by rank: hang the shorter tree under the taller one
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1

    def connected(self, x: int, y: int) -> bool:
        """Reports whether x and y are in the same set."""
        return self.find(x) == self.find(y)
