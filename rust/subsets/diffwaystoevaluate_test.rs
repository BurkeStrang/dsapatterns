use super::diffwaystoevaluate::diff_ways_to_evaluate_expression;

#[test]
fn test_diff_ways_to_evaluate_expression() {
    let tests = [
        ("parentheses addition", "2+3*2", vec![8, 10]),
        ("parentheses multiple", "2*4-3*5", vec![-22, 10, -7, 10, 25]),
    ];
    for (name, input, want) in tests {
        let got = diff_ways_to_evaluate_expression(input);
        assert_eq!(got, want, "{name}: diff_ways_to_evaluate_expression()");
    }
}
