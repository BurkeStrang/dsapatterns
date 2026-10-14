// Given a number n, return the numbers from 1 to n as strings, but with
// "Fizz" for the multiples of 3, "Buzz" for the multiples of 5, and
// "FizzBuzz" for the multiples of both.

pub fn fizz_buzz(n: u32) -> Vec<String> {
    let mut res = Vec::new();
    for i in 1..=n {
        if i % 15 == 0 {
            res.push("FizzBuzz".to_string());
        } else if i % 5 == 0 {
            res.push("Buzz".to_string());
        } else if i % 3 == 0 {
            res.push("Fizz".to_string());
        } else {
            res.push(i.to_string());
        }
    }
    res
}
