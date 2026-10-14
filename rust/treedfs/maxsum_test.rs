use super::maxsum::find_maximum_path_sum;
use super::shared::tree;

#[test]
fn test_find_maximum_path_sum() {
    let tests = [
        // 2 + 1 + 3
        ("simple tree", "[1, 2, 3]", 6),
        // 15 + 20 + 7
        (
            "tree with negative values",
            "[-10, 9, 20, null, null, 15, 7]",
            42,
        ),
    ];
    for (name, root, want) in tests {
        let got = find_maximum_path_sum(&tree(root));
        assert_eq!(got, want, "{name}: find_maximum_path_sum()");
    }
}
