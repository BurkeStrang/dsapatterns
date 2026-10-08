using System.Text;

namespace DsaPatterns.Greedy;

// Given a string s containing 0 to 9 digits, create the largest possible
// palindromic number using the string characters.
// It should not contain leading zeroes.
// A palindromic number reads the same backward as forward.
// If it's not possible to form such a number using all digits of the given
// string, you can skip some of them.
//
// Example 1
// Input: s = "323211444"
// Expected Output: "432141234"
// Justification: This is the largest palindromic number that can be formed from
// the given digits.
//
// Example 2
// Input: s = "998877"
// Expected Output: "987789"
// Justification: "987789" is the largest palindrome that can be formed.
//
// Example 3
// Input: s = "54321"
// Expected Output: "5"
// Justification: Only "5" can form a valid palindromic number as other digits
// cannot be paired.

internal static class LargestPalindromicNumber
{
    internal static string LargestPalindromic(string s)
    {
        // StringBuilder to store first half of the palindrome
        StringBuilder firstHalf = new();
        int[] frequency = new int[10]; // Frequency array for digits 0-9

        // Count the frequency of each digit in the input number
        for (int i = 0; i < s.Length; i++)
        {
            int val = s[i] - '0';
            frequency[val]++;
        }

        int middle = -1; // Variable to store the middle digit if needed

        // Iterate from the highest digit (9) to the lowest (0)
        for (int i = 9; i >= 0; i--)
        {
            if (frequency[i] != 0 && (i != 0 || firstHalf.Length > 0))
            {
                int count = frequency[i];
                while (count > 1)
                {
                    // Append the digit to firstHalf
                    firstHalf.Append((char)(i + '0'));
                    count -= 2; // Use two of the digit for the first half
                }

                if (count == 1 && middle == -1)
                {
                    // Assign the middle digit if it's the largest odd-count
                    // digit
                    middle = i;
                }
            }
        }

        // Create secondHalf as a reversed copy of firstHalf
        string secondHalf = ReverseString(firstHalf.ToString());

        if (middle != -1) // Append the middle digit if it exists
        {
            firstHalf.Append((char)(middle + '0'));
        }

        firstHalf.Append(secondHalf); // Append the reversed first half

        if (firstHalf.Length > 0)
        {
            return firstHalf.ToString(); // Return the final palindrome
        }

        return "0";
    }

    private static string ReverseString(string s)
    {
        char[] chars = s.ToCharArray();
        for (
            int left = 0, right = chars.Length - 1;
            left < right;
            left++, right--
        )
        {
            (chars[left], chars[right]) = (chars[right], chars[left]);
        }

        return new string(chars);
    }
}
