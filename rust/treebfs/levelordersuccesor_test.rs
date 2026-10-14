use super::levelordersuccesor::find_successor;
use super::shared::tree;

#[test]
fn test_find_successor() {
    let tests = [
        ("Example 1", "[1, 2, 3, 4, 5]", 3, Some(4)),
        ("Example 2", "[12, 7, 1, 9, null, 10, 5]", 9, Some(10)),
        ("Example 3", "[12, 7, 1, 9, null, 10, 5]", 12, Some(7)),
        ("No successor (last node)", "[1, 2]", 2, None),
        ("Empty tree", "[]", 1, None),
    ];
    for (name, root, key, want) in tests {
        let got = find_successor(&tree(root), key);
        // compare by value
        let got = got.map(|node| node.borrow().val);
        assert_eq!(got, want, "{name}: find_successor()");
    }
}
