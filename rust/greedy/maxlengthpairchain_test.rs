use super::maxlengthpairchain::find_longest_chain;

#[test]
fn test_find_longest_chain() {
    let tests = [
        ("Example 1", vec![[1, 2], [3, 4], [2, 3]], 2),
        ("Example 2", vec![[5, 6], [1, 2], [8, 9], [2, 3]], 3),
        (
            "Example 3",
            vec![[7, 8], [5, 6], [1, 2], [3, 5], [4, 5], [2, 3]],
            3,
        ),
    ];
    for (name, mut pairs, want) in tests {
        let got = find_longest_chain(&mut pairs);
        assert_eq!(got, want, "{name}: find_longest_chain()");
    }
}
