from unionfind.shared import UnionFind


def test_union_find() -> None:
    uf = UnionFind(5)
    assert not uf.connected(0, 1), "connected before any union"

    uf.unite(0, 1)
    uf.unite(3, 4)
    uf.unite(1, 1)
    assert uf.connected(0, 1)
    assert not uf.connected(1, 3)

    uf.unite(1, 4)
    assert uf.connected(0, 3), "connected after joining both sets"
    assert not uf.connected(2, 0)
