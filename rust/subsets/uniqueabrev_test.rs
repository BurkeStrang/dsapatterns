use super::uniqueabrev::generate_generalized_abbreviation;

#[test]
fn test_generate_generalized_abbreviation() {
    let tests = [(
        "word",
        "word",
        vec![
            "word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2",
            "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4",
        ],
    )];
    for (name, word, mut want) in tests {
        let mut got = generate_generalized_abbreviation(word);
        // the abbreviations may come back in any order
        got.sort();
        want.sort();
        assert_eq!(got, want, "{name}: generate_generalized_abbreviation()");
    }
}
