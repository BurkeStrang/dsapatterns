use super::comparingstringsbackslash::compare;

#[test]
fn test_compare() {
    let tests = [
        ("Example 1", "xy#z", "xzz#", true),
        ("Example 2", "xy#z", "xyz#", false),
        ("Example 3", "xp#", "xyz##", true),
        ("Example 4", "xywrrmp", "xywrrmu#p", true),
    ];
    for (name, str1, str2, want) in tests {
        let got = compare(str1, str2);
        assert_eq!(got, want, "{name}: compare({str1:?}, {str2:?})");
    }
}
