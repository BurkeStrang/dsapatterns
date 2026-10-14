use super::reversesublist::reverse_sub;
use super::shared::{build_list, list_to_vec};

#[test]
fn test_reverse_sub() {
    let tests = [
        (
            "reverse middle sublist",
            vec![1, 2, 3, 4, 5],
            2,
            4,
            vec![1, 4, 3, 2, 5],
        ),
        ("reverse entire list", vec![1, 2, 3], 1, 3, vec![3, 2, 1]),
        (
            "reverse single node (no change)",
            vec![1, 2],
            2,
            2,
            vec![1, 2],
        ),
        ("reverse head only", vec![1, 2], 1, 1, vec![1, 2]),
        ("reverse first two", vec![1, 2, 3], 1, 2, vec![2, 1, 3]),
        ("reverse last two", vec![1, 2, 3], 2, 3, vec![1, 3, 2]),
        ("empty list", vec![], 1, 1, vec![]),
    ];
    for (name, head, p, q, want) in tests {
        let got = reverse_sub(build_list(&head), p, q);
        assert_eq!(list_to_vec(&got), want, "{name}: reverse_sub()");
    }
}
