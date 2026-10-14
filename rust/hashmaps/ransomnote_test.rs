use super::ransomnote::can_construct;

#[test]
fn test_can_construct() {
    let tests = [
        (
            "can construct hello from hellworld",
            "hello",
            "hellworld",
            true,
        ),
        ("can construct notes from stoned", "notes", "stoned", true),
        ("cannot construct apple from pale", "apple", "pale", false),
        ("exact match", "abc", "abc", true),
        ("not enough letters", "aabb", "ab", false),
        ("empty ransom note", "", "anything", true),
        ("empty magazine", "a", "", false),
    ];
    for (name, ransom_note, magazine, want) in tests {
        let got = can_construct(ransom_note, magazine);
        assert_eq!(got, want, "{name}: can_construct()");
    }
}
