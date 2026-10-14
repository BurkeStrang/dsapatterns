use super::shared::{build_nodes, same_node};
use super::startofcycle::find_cycle_start;

#[test]
fn test_find_cycle_start() {
    // (name, values, index the last node points back to)
    let tests = [
        ("cycle at node 2", vec![1, 2, 3, 4], Some(1)),
        ("cycle at the head", vec![1, 2, 3], Some(0)),
        ("no cycle", vec![1, 2, 3], None),
    ];
    for (name, vals, cycle_start) in tests {
        let nodes = build_nodes(&vals);
        let want = cycle_start.map(|i| nodes[i].clone());
        nodes[nodes.len() - 1].borrow_mut().next = want.clone();

        let got = find_cycle_start(&Some(nodes[0].clone()));
        assert!(
            same_node(&got, &want),
            "{name}: find_cycle_start() = {:?}, want {:?}",
            got.map(|node| node.borrow().val),
            want.map(|node| node.borrow().val),
        );
    }
}
