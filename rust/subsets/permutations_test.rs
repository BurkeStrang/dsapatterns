use super::permutations::find_permutations;

#[test]
fn test_find_permutations() {
    let tests = [(
        "3 elements",
        vec![1, 2, 3],
        vec![
            vec![1, 2, 3],
            vec![1, 3, 2],
            vec![2, 1, 3],
            vec![2, 3, 1],
            vec![3, 1, 2],
            vec![3, 2, 1],
        ],
    )];
    for (name, nums, want) in tests {
        let mut got = find_permutations(&nums);
        // the permutations may come back in any order
        got.sort();
        assert_eq!(got, want, "{name}: find_permutations()");
    }
}
