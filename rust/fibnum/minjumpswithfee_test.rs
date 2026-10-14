use super::minjumpswithfee::find_min_fee;

#[test]
fn test_find_min_fee() {
    let tests = [
        ("Example 1", vec![1, 2, 5, 2, 1, 2], 3),
        ("Example 2", vec![2, 3, 4, 5], 5),
    ];
    for (name, fee, want) in tests {
        let got = find_min_fee(&fee);
        assert_eq!(got, want, "{name}: find_min_fee()");
    }
}
