use super::levelaverages::level_average;
use super::shared::{equal_float_slices, tree};

#[test]
fn test_level_average() {
    let tests = [
        ("Example 1", "[1, 2, 3, 4, 5, 6, 7]", vec![1.0, 2.5, 5.5]),
        (
            "Example 2",
            "[12, 7, 1, null, 9, 10, 5]",
            vec![12.0, 4.0, 8.0],
        ),
        ("Empty tree", "[]", vec![]),
    ];
    for (name, root, want) in tests {
        let got = level_average(&tree(root));
        assert!(
            equal_float_slices(&got, &want),
            "{name}: level_average() = {got:?}, want {want:?}"
        );
    }
}
