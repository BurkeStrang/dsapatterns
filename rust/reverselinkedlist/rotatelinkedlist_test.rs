use super::rotatelinkedlist::rotate;
use super::shared::{build_list, list_to_vec};

#[test]
fn test_rotate() {
    let tests = [
        ("rotate by 2", vec![1, 2, 3, 4, 5], 2, vec![4, 5, 1, 2, 3]),
        ("rotate by 0 (no change)", vec![1, 2, 3], 0, vec![1, 2, 3]),
        (
            "rotate by length (no change)",
            vec![1, 2, 3],
            3,
            vec![1, 2, 3],
        ),
        (
            "rotate by more than length",
            vec![1, 2, 3],
            5,
            vec![2, 3, 1],
        ),
        ("single node", vec![1], 1, vec![1]),
        ("empty list", vec![], 3, vec![]),
    ];
    for (name, head, rotations, want) in tests {
        let got = rotate(build_list(&head), rotations);
        assert_eq!(list_to_vec(&got), want, "{name}: rotate()");
    }
}
