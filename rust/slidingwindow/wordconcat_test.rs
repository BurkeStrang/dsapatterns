use super::wordconcat::find_word_concatenation;

#[test]
fn test_find_word_concatenation() {
    let tests = [
        ("Example 1", "catfoxcat", vec!["cat", "fox"], vec![0, 3]),
        ("Example 2", "catcatfoxfox", vec!["cat", "fox"], vec![3]),
        ("No match", "abcdefg", vec!["hi", "jk"], vec![]),
    ];
    for (name, s, words, want) in tests {
        let got = find_word_concatenation(s, &words);
        assert_eq!(got, want, "{name}: find_word_concatenation()");
    }
}
