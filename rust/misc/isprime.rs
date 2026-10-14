// A prime is a number bigger than 1 that only 1 and the number itself divide
// without a remainder.

pub fn is_prime(n: u32) -> bool {
    // no number you can divide n by without leaving a remainder other than 1
    // and n itself
    if n < 2 {
        return false;
    }
    if n == 2 || n == 3 {
        return true;
    }
    if n % 2 == 0 {
        return false;
    }

    let mut i = 3;
    while i * i <= n {
        if n % i == 0 {
            return false;
        }
        i += 2;
    }

    true
}

pub fn count_primes(n: u32) -> usize {
    let mut count = 0;
    for i in 2..=n {
        if is_prime(i) {
            count += 1;
        }
    }
    count
}

pub fn get_primes(n: u32) -> Vec<u32> {
    let mut res = Vec::new();
    for i in 2..=n {
        if is_prime(i) {
            res.push(i);
        }
    }
    res
}
