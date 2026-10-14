use super::shared::tree;
use super::treediameter::find_diameter;

#[test]
fn test_find_diameter() {
    let tests = [
        ("Single node", "[1]", 0),
        // Path: 4-2-1-3 or 5-2-1-3
        //            1
        //           / \
        //          2   3
        //         / \
        //        4   5
        ("Simple tree", "[1, 2, 3, 4, 5]", 4),
        // Path: 4-1-2-3
        //       1
        //      / \
        //     4   2
        //          \
        //           3
        ("Lopsided tree", "[1, 4, 2, null, null, null, 3]", 4),
    ];
    for (name, root, want) in tests {
        let got = find_diameter(&tree(root));
        assert_eq!(got, want, "{name}: find_diameter()");
    }
}
