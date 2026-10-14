use super::findmiddle::find_middle;
use super::shared::build_list;

#[test]
fn test_find_middle() {
    let tests = [
        ("odd length list", vec![1, 2, 3, 4, 5], Some(3)),
        ("even length list", vec![1, 2, 3, 4], Some(3)),
        ("single node", vec![1], Some(1)),
        ("two nodes", vec![1, 2], Some(2)),
        ("empty list", vec![], None),
    ];
    for (name, head, want) in tests {
        let got = find_middle(&build_list(&head));
        let got = got.map(|node| node.borrow().val);
        assert_eq!(got, want, "{name}: find_middle()");
    }
}
