use super::fizzbuzz::fizz_buzz;

#[test]
fn test_fizz_buzz() {
    let tests = [
        ("5", 5, vec!["1", "2", "Fizz", "4", "Buzz"]),
        (
            "15",
            15,
            vec![
                "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz",
                "Buzz", "11", "Fizz", "13", "14", "FizzBuzz",
            ],
        ),
    ];
    for (name, n, want) in tests {
        let got = fizz_buzz(n);
        assert_eq!(got, want, "{name}: fizz_buzz()");
    }
}
