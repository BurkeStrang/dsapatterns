use super::searchsuggestionsystem::suggested_products;

#[test]
fn test_suggested_products() {
    let tests = [
        (
            "Test Case 1",
            vec!["mobile", "mouse", "moneypot", "monitor", "mousepad"],
            "mouse",
            vec![
                vec!["mobile", "moneypot", "monitor"],
                vec!["mobile", "moneypot", "monitor"],
                vec!["mouse", "mousepad"],
                vec!["mouse", "mousepad"],
                vec!["mouse", "mousepad"],
            ],
        ),
        (
            "Test Case 2",
            vec!["havana"],
            "havana",
            vec![vec!["havana"]; 6],
        ),
    ];
    for (name, products, search_word, want) in tests {
        let got = suggested_products(&products, search_word);
        assert_eq!(got, want, "{name}: suggested_products()");
    }
}
