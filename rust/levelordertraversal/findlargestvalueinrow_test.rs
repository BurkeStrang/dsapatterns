use super::findlargestvalueinrow::largest_values;
use super::shared::tree;

#[test]
fn test_largest_values() {
    let tests = [
        ("Example 1", "[1, 2, 3, 4, 5, null, 6]", vec![1, 3, 6]),
        (
            "Example 2",
            "[7, 4, 8, 2, 5, null, 9, null, 3]",
            vec![7, 8, 9, 3],
        ),
        ("Example 3", "[10, 5]", vec![10, 5]),
        ("Empty tree", "[]", vec![]),
    ];
    for (name, root, want) in tests {
        let got = largest_values(&tree(root));
        assert_eq!(got, want, "{name}: largest_values()");
    }
}
