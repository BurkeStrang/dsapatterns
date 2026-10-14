use super::indexparis::index_pairs;

#[test]
fn test_index_pairs() {
    let tests = [
        (
            "Test Case 1",
            "thestarsareout",
            vec!["star", "stars", "are"],
            vec![[3, 6], [3, 7], [8, 10]],
        ),
        (
            "Test Case 2",
            "bluebirdskyscraper",
            vec!["blue", "bird", "sky"],
            vec![[0, 3], [4, 7], [8, 10]],
        ),
    ];
    for (name, text, words, want) in tests {
        let got = index_pairs(text, &words);
        assert_eq!(got, want, "{name}: index_pairs()");
    }
}
