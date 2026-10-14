use super::palindromicpartition::find_mpp_cuts;

#[test]
fn test_find_mpp_cuts() {
    let tests = [
        ("Example 1", "abdbca", 3),
        ("Example 2", "cddpd", 2),
        ("Example 3", "pqr", 2),
        ("Example 4", "pp", 0),
    ];
    for (name, st, want) in tests {
        let got = find_mpp_cuts(st);
        assert_eq!(got, want, "{name}: find_mpp_cuts()");
    }
}
