use super::reverse::reverse;
use super::shared::{build_list, list_to_vec};

#[test]
fn test_reverse() {
    let tests = [
        ("multiple nodes", vec![1, 2, 3], vec![3, 2, 1]),
        ("single node", vec![1], vec![1]),
        ("empty list", vec![], vec![]),
    ];
    for (name, head, want) in tests {
        let got = reverse(build_list(&head));
        assert_eq!(list_to_vec(&got), want, "{name}: reverse()");
    }
}
