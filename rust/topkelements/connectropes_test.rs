use super::connectropes::minimum_cost_to_connect_ropes;

#[test]
fn test_minimum_cost_to_connect_ropes() {
    let tests = [
        ("Example 1", vec![1, 2, 3, 4, 5], 33),
        ("Example 2", vec![3, 4, 5, 6], 36),
        ("Example 3", vec![1, 3, 11, 5, 2], 42),
    ];
    for (name, rope_lengths, want) in tests {
        let got = minimum_cost_to_connect_ropes(&rope_lengths);
        assert_eq!(got, want, "{name}: minimum_cost_to_connect_ropes()");
    }
}
