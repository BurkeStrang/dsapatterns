use super::reversealtksublist::reverse_alt;
use super::shared::{build_list, list_to_vec};

#[test]
fn test_reverse_alt() {
    let tests = [
        (
            "reverse every alternate 2 nodes",
            vec![1, 2, 3, 4, 5, 6],
            2,
            vec![2, 1, 3, 4, 6, 5],
        ),
        (
            "reverse every alternate 3 nodes",
            vec![1, 2, 3, 4, 5, 6, 7],
            3,
            vec![3, 2, 1, 4, 5, 6, 7],
        ),
        ("k greater than length", vec![1, 2], 5, vec![2, 1]),
        ("single node", vec![1], 2, vec![1]),
        ("empty list", vec![], 2, vec![]),
    ];
    for (name, head, k, want) in tests {
        let got = reverse_alt(build_list(&head), k);
        assert_eq!(list_to_vec(&got), want, "{name}: reverse_alt()");
    }
}
