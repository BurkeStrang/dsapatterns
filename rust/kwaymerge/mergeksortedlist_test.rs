use super::mergeksortedlist::{ListNode, merge};

fn build_list(vals: &[i32]) -> Option<Box<ListNode>> {
    let mut head = None;
    for &val in vals.iter().rev() {
        head = Some(Box::new(ListNode { val, next: head }));
    }
    head
}

#[test]
fn test_merge() {
    let tests = [
        (
            "Example 1",
            vec![vec![2, 6, 8], vec![3, 6, 7], vec![1, 3, 4]],
            vec![1, 2, 3, 3, 4, 6, 6, 7, 8],
        ),
        (
            "Example 2",
            vec![vec![5, 8, 9], vec![1, 7]],
            vec![1, 5, 7, 8, 9],
        ),
        ("An empty list among them", vec![vec![], vec![1]], vec![1]),
    ];
    for (name, lists, want) in tests {
        let lists = lists.iter().map(|vals| build_list(vals)).collect();
        let got = merge(lists);
        assert_eq!(got, build_list(&want), "{name}: merge()");
    }
}
