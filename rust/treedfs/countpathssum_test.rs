use super::countpathssum::count_paths;
use super::shared::tree;

#[test]
fn test_count_paths() {
    let tests = [
        // Paths: [1,2], [3]
        ("Example 1: Two paths", "[1, 2, 3]", 3, 2),
        // Paths: [5,3], [5,2,1], [-3,11]
        (
            "Example 2: Multiple paths",
            "[10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]",
            8,
            3,
        ),
        ("Example 3: No path", "[1, 2]", 100, 0),
        ("Example 4: Empty tree", "[]", 0, 0),
    ];
    for (name, root, target_sum, want) in tests {
        let got = count_paths(&tree(root), target_sum);
        assert_eq!(got, want, "{name}: count_paths()");
    }
}
