use super::dailytemp::daily_temperatures;

#[test]
fn test_daily_temperatures() {
    let tests = [
        (
            "Example 1",
            vec![70, 73, 75, 71, 69, 72, 76, 73],
            vec![1, 1, 4, 2, 1, 1, 0, 0],
        ),
        ("Example 2", vec![73, 72, 71, 70], vec![0, 0, 0, 0]),
        ("Example 3", vec![70, 71, 72, 73], vec![1, 1, 1, 0]),
        ("All same", vec![60, 60, 60], vec![0, 0, 0]),
        ("Single element", vec![80], vec![0]),
    ];
    for (name, temperatures, want) in tests {
        let got = daily_temperatures(&temperatures);
        assert_eq!(got, want, "{name}: daily_temperatures()");
    }
}
