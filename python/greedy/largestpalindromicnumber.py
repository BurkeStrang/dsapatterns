"""
Given a string s containing 0 to 9 digits, create the largest possible
palindromic number using the string characters.
It should not contain leading zeroes.
A palindromic number reads the same backward as forward.
If it's not possible to form such a number using all digits of the given
string, you can skip some of them.

Example 1
Input: s = "323211444"
Expected Output: "432141234"
Justification: This is the largest palindromic number that can be formed from
the given digits.

Example 2
Input: s = "998877"
Expected Output: "987789"
Justification: "987789" is the largest palindrome that can be formed.

Example 3
Input: s = "54321"
Expected Output: "5"
Justification: Only "5" can form a valid palindromic number as other digits
cannot be paired.
"""


def largest_palindromic(s: str) -> str:
    first_half: list[str] = []  # The first half of the palindrome
    frequency = [0] * 10  # Frequency array for digits 0-9

    # Count the frequency of each digit in the input number
    for digit in s:
        frequency[int(digit)] += 1

    middle: str | None = None  # The middle digit, if one is needed

    # Iterate from the highest digit (9) to the lowest (0)
    for d in range(9, -1, -1):
        count = frequency[d]
        digit = str(d)
        # a number can't start with 0, so skip the zeros until there is
        # something in front of them
        if count != 0 and (d != 0 or first_half):
            while count > 1:
                first_half.append(digit)  # Append the digit to first_half
                count -= 2  # Use two of the digit for the two halves
            if count == 1 and middle is None:
                # The middle digit is the largest digit with an odd count
                middle = digit

    # Create second_half as a reversed copy of first_half
    second_half = first_half[::-1]

    # Append the middle digit if it exists, then the reversed first half
    result = "".join(first_half) + (middle or "") + "".join(second_half)

    if result == "":
        return "0"
    return result  # Return the final palindrome
