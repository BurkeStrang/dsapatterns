use super::findcyclelength::find_cycle_length;
use super::shared::build_nodes;

#[test]
fn test_find_cycle_length() {
    // (name, values, index the last node points back to, want)
    let tests = [
        // cycle starts at the second node, length 3
        ("cycle of length 3", vec![1, 2, 3, 4], Some(1), 3),
        ("no cycle", vec![1, 2, 3], None, 0),
        ("cycle of length 1 (self loop)", vec![1], Some(0), 1),
    ];
    for (name, vals, cycle_start, want) in tests {
        let nodes = build_nodes(&vals);
        if let Some(i) = cycle_start {
            nodes[nodes.len() - 1].borrow_mut().next = Some(nodes[i].clone());
        }
        let got = find_cycle_length(&Some(nodes[0].clone()));
        assert_eq!(got, want, "{name}: find_cycle_length()");
    }
}
