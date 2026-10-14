use super::largestpalindromicnumber::largest_palindromic;

#[test]
fn test_largest_palindromic() {
    let tests = [
        ("Example 1", "323211444", "432141234"),
        ("Example 2", "998877", "987789"),
        ("Example 3", "54321", "5"),
        ("Only zeros", "000", "0"),
        ("Zeros in the middle", "10001", "10001"),
    ];
    for (name, s, want) in tests {
        let got = largest_palindromic(s);
        assert_eq!(got, want, "{name}: largest_palindromic()");
    }
}
