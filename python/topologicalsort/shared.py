"""Helpers shared by the topological sort tests."""


def is_topological_order(
    order: list[int], vertices: int, edges: list[tuple[int, int]]
) -> bool:
    """Reports whether order lists every vertex once, with each edge's parent
    before its child. A graph usually has more than one valid order, so the
    tests check the order this way instead of comparing it with a fixed
    answer."""
    if sorted(order) != list(range(vertices)):
        return False
    # position[v] is where vertex 'v' sits in the order
    position = {vertex: i for i, vertex in enumerate(order)}
    return all(position[parent] < position[child] for parent, child in edges)
