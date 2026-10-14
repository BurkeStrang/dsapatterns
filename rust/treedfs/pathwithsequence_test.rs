use super::pathwithsequence::find_path;
use super::shared::tree;

#[test]
fn test_find_path() {
    let tests = [
        (
            "Example 1: Path exists",
            "[1, 7, 9, null, null, 2, 9]",
            vec![1, 9, 9],
            true,
        ),
        (
            "Example 2: Path does not exist",
            "[1, 0, 1, 1, 6, null, 5]",
            vec![1, 0, 7],
            false,
        ),
        ("Example 3: Empty sequence", "[1, 2]", vec![], false),
        ("Example 4: Empty tree", "[]", vec![1], false),
        ("Example 5: Single node match", "[5]", vec![5], true),
    ];
    for (name, root, sequence, want) in tests {
        let got = find_path(&tree(root), &sequence);
        assert_eq!(got, want, "{name}: find_path()");
    }
}
