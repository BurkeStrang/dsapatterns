use super::linkedlistcycle::has_cycle;
use super::shared::build_nodes;

#[test]
fn test_has_cycle() {
    // (name, values, index the last node points back to, want)
    let tests = [
        ("no cycle", vec![1, 2, 3], None, false),
        ("cycle exists", vec![1, 2, 3], Some(0), true),
    ];
    for (name, vals, cycle_start, want) in tests {
        let nodes = build_nodes(&vals);
        if let Some(i) = cycle_start {
            nodes[nodes.len() - 1].borrow_mut().next = Some(nodes[i].clone());
        }
        let got = has_cycle(&Some(nodes[0].clone()));
        assert_eq!(got, want, "{name}: has_cycle()");
    }
}
