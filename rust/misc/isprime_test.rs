use super::isprime::{count_primes, get_primes, is_prime};

#[test]
fn test_is_prime() {
    let tests = [
        (1, false),
        (2, true),
        (3, true),
        (4, false),
        (5, true),
        (167, true),
    ];
    for (n, want) in tests {
        let got = is_prime(n);
        assert_eq!(got, want, "is_prime({n})");
    }
}

#[test]
fn test_count_primes() {
    let tests = [(1, 0), (10, 4), (100, 25), (1000, 168), (10000, 1229)];
    for (n, want) in tests {
        let got = count_primes(n);
        assert_eq!(got, want, "count_primes({n})");
    }
}

#[test]
fn test_get_primes() {
    let tests = [
        (1, vec![]),
        (10, vec![2, 3, 5, 7]),
        (20, vec![2, 3, 5, 7, 11, 13, 17, 19]),
        (30, vec![2, 3, 5, 7, 11, 13, 17, 19, 23, 29]),
        (
            100,
            vec![
                2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
                61, 67, 71, 73, 79, 83, 89, 97,
            ],
        ),
    ];
    for (n, want) in tests {
        let got = get_primes(n);
        assert_eq!(got, want, "get_primes({n})");
    }
}
