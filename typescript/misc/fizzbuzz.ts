// Given a number n, return the numbers from 1 to n as strings, but with
// "Fizz" for the multiples of 3, "Buzz" for the multiples of 5, and
// "FizzBuzz" for the multiples of both.

export function fizzBuzz(n: number): string[] {
  const res: string[] = [];
  for (let i = 1; i <= n; i++) {
    if (i % 15 === 0) {
      res.push("FizzBuzz");
    } else if (i % 5 === 0) {
      res.push("Buzz");
    } else if (i % 3 === 0) {
      res.push("Fizz");
    } else {
      res.push(String(i));
    }
  }
  return res;
}
