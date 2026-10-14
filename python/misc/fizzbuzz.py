"""
Given a number n, return the numbers from 1 to n as strings, but with
"Fizz" for the multiples of 3, "Buzz" for the multiples of 5, and
"FizzBuzz" for the multiples of both.
"""


def fizz_buzz(n: int) -> list[str]:
    res: list[str] = []
    for i in range(1, n + 1):
        if i % 15 == 0:
            res.append("FizzBuzz")
        elif i % 5 == 0:
            res.append("Buzz")
        elif i % 3 == 0:
            res.append("Fizz")
        else:
            res.append(str(i))
    return res
