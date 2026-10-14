use super::complementbase10::bitwise_complement;

#[test]
fn test_bitwise_complement() {
    let tests = [
        // number: 5 (binary 101) -> complement: 2 (binary 010)
        ("Example 1", 5, 2),
        // number: 7 (binary 111) -> complement: 0 (binary 000)
        ("Example 2", 7, 0),
        // number: 10 (binary 1010) -> complement: 5 (binary 0101)
        ("Example 3", 10, 5),
    ];
    for (name, num, want) in tests {
        let got = bitwise_complement(num);
        assert_eq!(got, want, "{name}: bitwise_complement()");
    }
}
