use super::reverseksublist::reverse_k_sub;
use super::shared::{build_list, list_to_vec};

#[test]
fn test_reverse_k_sub() {
    let tests = [
        (
            "reverse every 2 nodes",
            vec![1, 2, 3, 4, 5],
            2,
            vec![2, 1, 4, 3, 5],
        ),
        (
            "reverse every 3 nodes",
            vec![1, 2, 3, 4, 5],
            3,
            vec![3, 2, 1, 5, 4],
        ),
        ("k greater than length", vec![1, 2], 5, vec![2, 1]),
        ("single node", vec![1], 2, vec![1]),
        ("empty list", vec![], 2, vec![]),
    ];
    for (name, head, k, want) in tests {
        let got = reverse_k_sub(build_list(&head), k);
        assert_eq!(list_to_vec(&got), want, "{name}: reverse_k_sub()");
    }
}
