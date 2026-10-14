use super::mergesimiliaritems::merge_similar_items;

#[test]
fn test_merge_similar_items() {
    let tests = [
        (
            "Example 1",
            vec![[1, 2], [4, 3]],
            vec![[2, 1], [4, 3], [3, 4]],
            vec![[1, 2], [2, 1], [3, 4], [4, 6]],
        ),
        ("Example 2", vec![[5, 5]], vec![[5, 10]], vec![[5, 15]]),
        (
            "Example 3",
            vec![[1, 1], [2, 2]],
            vec![[3, 3]],
            vec![[1, 1], [2, 2], [3, 3]],
        ),
        (
            "Unsorted input",
            vec![[9, 1], [2, 2]],
            vec![[5, 3], [2, 4]],
            vec![[2, 6], [5, 3], [9, 1]],
        ),
    ];
    for (name, items1, items2, want) in tests {
        let got = merge_similar_items(&items1, &items2);
        assert_eq!(got, want, "{name}: merge_similar_items()");
    }
}
