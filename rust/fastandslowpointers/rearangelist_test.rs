use super::rearangelist::rearange_list;
use super::shared::{build_list, list_to_vec};

#[test]
fn test_rearange_list() {
    let tests = [
        ("even length list", vec![1, 2, 3, 4], vec![1, 4, 2, 3]),
        ("odd length list", vec![1, 2, 3], vec![1, 3, 2]),
        ("single node", vec![1], vec![1]),
        ("empty list", vec![], vec![]),
    ];
    for (name, head, want) in tests {
        let got = rearange_list(build_list(&head));
        assert_eq!(list_to_vec(&got), want, "{name}: rearange_list()");
    }
}
