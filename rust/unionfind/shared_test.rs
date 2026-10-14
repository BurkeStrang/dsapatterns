use super::shared::UnionFind;

#[test]
fn test_union_find() {
    let mut uf = UnionFind::new(5);
    assert!(!uf.connected(0, 1), "connected(0, 1) before any union");

    uf.union(0, 1);
    uf.union(3, 4);
    uf.union(1, 1);
    assert!(uf.connected(0, 1), "connected(0, 1) after union(0, 1)");
    assert!(!uf.connected(1, 3), "connected(1, 3)");

    uf.union(1, 4);
    assert!(
        uf.connected(0, 3),
        "connected(0, 3) after joining both sets"
    );
    assert!(!uf.connected(2, 0), "connected(2, 0)");
}
