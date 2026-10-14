use super::happynum::is_happy;

#[test]
fn test_is_happy() {
    let tests = [
        ("Happy number 19", 19, true),
        ("Happy number 1", 1, true),
        ("Unhappy number 2", 2, false),
        ("Unhappy number 4", 4, false),
    ];
    for (name, num, want) in tests {
        let got = is_happy(num);
        assert_eq!(got, want, "{name}: is_happy({num})");
    }
}
