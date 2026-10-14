use super::pairwithtargetsum::search;

#[test]
fn test_search() {
    let tests = [
        (vec![1, 2, 3, 4, 6], 6, Some((1, 3))),
        (vec![2, 5, 9, 11], 11, Some((0, 2))),
        (vec![1, 2, 3, 4, 5], 10, None),
    ];
    for (arr, target, want) in tests {
        let got = search(&arr, target);
        assert_eq!(got, want, "search({arr:?}, {target})");
    }
}
