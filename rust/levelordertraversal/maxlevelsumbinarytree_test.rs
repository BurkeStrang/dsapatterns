use super::maxlevelsumbinarytree::max_level_sum;
use super::shared::tree;

#[test]
fn test_max_level_sum() {
    let tests = [
        ("Example 1", "[1, 20, 3, 4, 5, null, 8]", 2),
        (
            "Example 2",
            "[10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]",
            3,
        ),
        ("Example 3", "[5, 6, 7, 8, null, null, 9, 10]", 3),
        ("Single node", "[42]", 1),
        ("Negative values", "[-1, -2, -3]", 1),
    ];
    for (name, root, want) in tests {
        let got = max_level_sum(&tree(root));
        assert_eq!(got, want, "{name}: max_level_sum()");
    }
}
