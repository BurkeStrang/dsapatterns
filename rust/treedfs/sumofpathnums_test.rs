use super::shared::tree;
use super::sumofpathnums::find_sum_of_path_numbers;

#[test]
fn test_find_sum_of_path_numbers() {
    let tests = [
        // Paths: 12, 13 => 12+13=25
        ("Example 1", "[1, 2, 3]", 25),
        // Paths: 101, 106, 115 => 101+106+115=322
        //                       1
        //                     /   \
        //                    0     1
        //                   / \     \
        //                  1   6     5
        ("Example 2", "[1, 0, 1, 1, 6, null, 5]", 322),
        ("Single node", "[5]", 5),
        ("Empty tree", "[]", 0),
    ];
    for (name, root, want) in tests {
        let got = find_sum_of_path_numbers(&tree(root));
        assert_eq!(got, want, "{name}: find_sum_of_path_numbers()");
    }
}
