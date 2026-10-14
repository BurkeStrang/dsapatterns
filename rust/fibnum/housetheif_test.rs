use super::housetheif::find_max_steal;

#[test]
fn test_find_max_steal() {
    let tests = [
        ("Example 1", vec![2, 5, 1, 3, 6, 2, 4], 15),
        ("Example 2", vec![2, 10, 14, 8, 1], 18),
    ];
    for (name, wealth, want) in tests {
        let got = find_max_steal(&wealth);
        assert_eq!(got, want, "{name}: find_max_steal()");
    }
}
