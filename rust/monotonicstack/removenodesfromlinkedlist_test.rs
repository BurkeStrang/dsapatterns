use super::removenodesfromlinkedlist::remove_nodes;
use super::shared::{build_list, list_to_vec};

#[test]
fn test_remove_nodes() {
    let tests = [
        ("Example 1", vec![5, 3, 7, 4, 2, 1], vec![7, 4, 2, 1]),
        ("Example 2", vec![1, 2, 3, 4, 5], vec![5]),
        ("Example 3", vec![5, 4, 3, 2, 1], vec![5, 4, 3, 2, 1]),
        ("Empty list", vec![], vec![]),
    ];
    for (name, head, want) in tests {
        let got = remove_nodes(build_list(&head));
        assert_eq!(list_to_vec(&got), want, "{name}: remove_nodes()");
    }
}
