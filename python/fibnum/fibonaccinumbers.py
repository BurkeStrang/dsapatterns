"""
Write a function to calculate the nth Fibonacci number.
Fibonacci numbers are a series of numbers in which each number is the sum of
the two preceding numbers.
First few Fibonacci numbers are: 0, 1, 1, 2, 3, 5, 8, ...
Mathematically we can define the Fibonacci numbers as:
 Fib(n) = Fib(n-1) + Fib(n-2), for n > 1
 Given that: Fib(0) = 0, and Fib(1) = 1
"""


def calculate_fibonacci(n: int) -> int:
    if n < 2:
        return n
    n1 = 0
    n2 = 1
    for _ in range(2, n + 1):
        n1, n2 = n2, n1 + n2
    return n2
