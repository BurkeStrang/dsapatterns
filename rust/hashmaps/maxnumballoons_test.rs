use super::maxnumballoons::max_number_of_balloons;

#[test]
fn test_max_number_of_balloons() {
    let tests = [
        ("Example 1", "balloonballoon", 2),
        ("Example 2", "bbaall", 0),
        ("Example 3", "balloonballoooon", 2),
    ];
    for (name, text, want) in tests {
        let got = max_number_of_balloons(text);
        assert_eq!(got, want, "{name}: max_number_of_balloons()");
    }
}
